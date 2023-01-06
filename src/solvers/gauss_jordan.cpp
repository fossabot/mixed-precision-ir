/** ************************************************************************
* gauss_jordan : example program comparing float vs posit matrix inversion algorithms
*
* @author:     Theodore Omtzigt
* @date:       2023-01-04
* @copyright:  Copyright (c) 2023 Stillwater Supercomputing, Inc.
* @license:    MIT Open Source license
*
* This file is part of the Mixed Precision Iterative Refinement project
* *************************************************************************
*/
//#include <chrono>
#include <boost/numeric/mtl/mtl.hpp>
#include <mtl_extensions.hpp>

// arithmetic types under study
#include <universal/number/cfloat/cfloat.hpp>
#include <universal/number/posit/posit.hpp>
#include <norms.hpp>
// matrix generators
#include <generators/matrix_generators.hpp>
#include <utils/print_utils.hpp>

namespace sw {
	namespace hprblas {

		template<typename Matrix>
		Matrix GaussJordanInversion(const Matrix& A) {
			using Scalar = typename mtl::Collection<Matrix>::value_type;

			size_t m = A.num_rows();
			size_t n = A.num_cols();
			Matrix a(n, m), inv(m, n);
			a = A; // you need a deep copy
			inv = Scalar(1);

			// Performing elementary operations 
			for (unsigned i = 0; i < m; ++i) {
				if (a[i][i] == 0) {
					unsigned c = 1;
					while (a[i + c][i] == 0 && (i + c) < n)	++c;
					if ((i + c) == n) break;

					for (unsigned j = i, k = 0; k < n; ++k) {
						std::swap(a[j][k], a[j + c][k]);
						std::cerr << "TBD" << std::endl; // need to create a permutation matrix
					}
				}
				// transform to diagonal matrix
				for (unsigned j = 0; j < m; j++) {
					if (i != j) {
						Scalar scale = a[j][i] / a[i][i];
						for (unsigned k = 0; k < n; ++k) {
							a[j][k] = a[j][k] - a[i][k] * scale;
							inv[j][k] = inv[j][k] - inv[i][k] * scale;
						}
					}
					//std::cout << i << "," << j << std::endl;
					//sw::hprblas::printMatrix(std::cout, "a", a);
					//sw::hprblas::printMatrix(std::cout, "inv", inv);
				}
			}
			// transform to identity matrix
			for (unsigned i = 0; i < m; ++i) {
				Scalar normalize = a[i][i];
				a[i][i] = Scalar(1);
				for (unsigned j = 0; j < n; ++j) {
					inv[i][j] /= normalize;
				}
			}
			//printMatrix(std::cout, "conversion", a);
			return inv;
		}
	} // namespace hprblas
} // namespace sw

template<typename Scalar>
void GenerateNumericalAnalysisTestCase(const std::string& header, unsigned N, bool verbose = false) {
	using namespace std;
	using namespace mtl;
	using namespace sw::universal;
	using namespace sw::hprblas;

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" << header << std::endl;
	using Vector = mtl::vec::dense_vector<Scalar>;
	using Matrix = mtl::mat::dense2D<Scalar>;

	Matrix H(N, N);
	GenerateHilbertMatrix(H, false);
	Matrix Hinv = GaussJordanInversion(H);
	Matrix Href(N, N);
	GenerateHilbertMatrixInverse(Href);
	Matrix I(N, N);  // H * Hinv should yield the identity matrix
	// TODO: this is not clear that for posits this would be a fused matrix multiply
	I = H * Hinv;

	if (verbose) {
		printMatrix(cout, "Hilbert matrix order 5", H);
		printMatrix(cout, "Hilbert inverse", Hinv);

		printMatrix(cout, "Hilbert inverse reference", Href);

		printMatrix(cout, "H * H^-1 => I", I);
	}

	// calculate the numerical error caused by the linear algebra computation
	Vector e(N), eprime(N), eabsolute(N), erelative(N);
	e = Scalar(1);
	// TODO: it is not clear that for posits this would be a fused matrix-vector operation
	eprime = I * e;
	printVector(cout, "reference vector", e);
	printVector(cout, "error vector", eprime);
	// absolute error
	eabsolute = e - eprime;
	printVector(cout, "absolute error vector", eabsolute);
	cout << "L1 norm   " << hex_format(l1_norm(eabsolute)) << "  " << l1_norm(eabsolute) << endl;
	cout << "L2 norm   " << hex_format(l2_norm(eabsolute)) << "  " << l2_norm(eabsolute) << endl;
	cout << "Linf norm " << hex_format(linf_norm(eabsolute)) << "  " << linf_norm(eabsolute) << endl;

	// relative error
	cout << "relative error\n";
	Scalar relative_error;
	relative_error = l1_norm(eabsolute) / l1_norm(e);
	cout << "L1 norm   " << hex_format(relative_error) << "  " << relative_error << endl;
	relative_error = l2_norm(eabsolute) / l2_norm(e);
	cout << "L2 norm   " << hex_format(relative_error) << "  " << relative_error << endl;
	relative_error = linf_norm(eabsolute) / linf_norm(e);
	cout << "Linf norm " << hex_format(relative_error) << "  " << relative_error << endl;

	// error volume
	cout << "error bounding box volume\n";
	cout << "Measured in Euclidean distance    : " << error_volume(linf_norm(eabsolute), N, false) << endl;
	cout << "Measured in ULPs                  : " << error_volume(linf_norm(eabsolute), N, true) << " ulps^" << N << endl;
	Scalar ulp = numeric_limits<Scalar>::epsilon();
	cout << "L-infinitiy norm measured in ULPs : " << linf_norm(eabsolute) / ulp << " ulps" << endl;
}

int main(int argc, char** argv)
try {
	using namespace std;
	using namespace mtl;
	using namespace sw::universal;

	unsigned N = 5; 
	GenerateNumericalAnalysisTestCase< posit<32, 2> >("posit<32,2>", N);
	cout << endl;
	GenerateNumericalAnalysisTestCase< float >("IEEE single precision", N);
	cout << endl;
	GenerateNumericalAnalysisTestCase< posit<64, 3> >("posit<64,3>", N);
	cout << endl;
	GenerateNumericalAnalysisTestCase< double >("IEEE double precision", N);
	cout << endl;
	GenerateNumericalAnalysisTestCase< posit<128, 4> >("posit<128,4>", N);
	cout << endl;
//	GenerateNumericalAnalysisTestCase< quad >("IEEE quad precision", N);

	return EXIT_SUCCESS;
}
catch (char const* msg) {
	std::cerr << msg << std::endl;
	return EXIT_FAILURE;
}
catch (const sw::universal::posit_arithmetic_exception& err) {
	std::cerr << "Uncaught posit arithmetic exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (const sw::universal::quire_exception& err) {
	std::cerr << "Uncaught quire exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (const sw::universal::posit_internal_exception& err) {
	std::cerr << "Uncaught posit internal exception: " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (std::runtime_error& err) {
	std::cerr << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch (...) {
	std::cerr << "Caught unknown exception" << std::endl;
	return EXIT_FAILURE;
}

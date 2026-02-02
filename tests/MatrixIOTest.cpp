#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <sstream>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(MatrixIOOpenFile)
{
  std::string file   = "../data/m3.csv";
  int         matrix = 3;

  MatrixXd expected(3, 3);
  expected << 0.680375, 0.59688, -0.329554, -0.211234, 0.823295, 0.536459, 0.566198, -0.604897, -0.444451;

  MatrixXd actual = matrixIO::openData(file, matrix);

  BOOST_TEST(expected.cwiseEqual(actual).all());
}

BOOST_AUTO_TEST_SUITE_END()
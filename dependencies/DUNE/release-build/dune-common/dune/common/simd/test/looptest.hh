// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from looptest.hh.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#ifndef DUNE_COMMON_SIMD_TEST_LOOPTEST_HH
#define DUNE_COMMON_SIMD_TEST_LOOPTEST_HH

#include <complex> // as inserted by substitutions

#include <dune/common/simd/test.hh>
#include <dune/common/simd/loop.hh>

namespace Dune {
  namespace Simd {

    extern template void
    UnitTest::checkType<LoopSIMD<char, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<char, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<char, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<char, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<char, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<char, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<char, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<char, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<char, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned char, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned char, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<unsigned char, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned char, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned char, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<unsigned char, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned char, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned char, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<unsigned char, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<signed char, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<signed char, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<signed char, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<signed char, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<signed char, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<signed char, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<signed char, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<signed char, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<signed char, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<short, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<short, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<short, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<short, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<short, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<short, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<short, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<short, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<short, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<int, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<int, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<int, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<int, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<int, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<int, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<int, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<int, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<int, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<long, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<long, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<long, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<long long, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<long long, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<long long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<long long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<long long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<long long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<long long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<long long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<long long, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned short, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned short, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<unsigned short, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned short, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned short, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<unsigned short, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned short, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned short, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<unsigned short, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<unsigned, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<unsigned, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<unsigned, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned long, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned long, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<unsigned long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<unsigned long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<unsigned long, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned long long, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<unsigned long long, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<unsigned long long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned long long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<unsigned long long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<unsigned long long, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned long long, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<unsigned long long, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<unsigned long long, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<bool, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<bool, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<bool, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<bool, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<bool, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<bool, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<bool, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<bool, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<bool, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<float, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<float, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<float, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<float, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<float, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<float, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<float, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<float, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<float, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<double, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<double, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<double, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<double, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<double, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<double, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<double, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<double, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<double, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<long double, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<long double, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<long double, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<long double, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<long double, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<long double, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<long double, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<long double, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<long double, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<std::complex<float>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<std::complex<float>, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<std::complex<float>, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<std::complex<float>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<std::complex<float>, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<std::complex<float>, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<std::complex<float>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<std::complex<float>, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<std::complex<float>, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<std::complex<double>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<std::complex<double>, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<std::complex<double>, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<std::complex<double>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<std::complex<double>, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<std::complex<double>, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<std::complex<double>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<std::complex<double>, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<std::complex<double>, 2>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<std::complex<long double>, 5> >();
    extern template void
    UnitTest::checkType<LoopSIMD<std::complex<long double>, 5, 64> >();
    extern template void
    UnitTest::checkType<LoopSIMD<LoopSIMD<std::complex<long double>, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<std::complex<long double>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<std::complex<long double>, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<LoopSIMD<LoopSIMD<std::complex<long double>, 2>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<std::complex<long double>, 5> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<std::complex<long double>, 5, 64> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<LoopSIMD<LoopSIMD<std::complex<long double>, 2>, 5> >();

  } //namespace Simd
} // namespace Dune

#endif

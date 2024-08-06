// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from standardtest.hh.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#ifndef DUNE_COMMON_SIMD_TEST_STANDARDTEST_HH
#define DUNE_COMMON_SIMD_TEST_STANDARDTEST_HH

#include <complex> // for substituted types

#include <dune/common/simd/test.hh>

namespace Dune {
  namespace Simd {

    extern template void UnitTest::checkType<char>();
    extern template void UnitTest::checkType<unsigned char>();
    extern template void UnitTest::checkType<signed char>();
    extern template void UnitTest::checkType<short>();
    extern template void UnitTest::checkType<int>();
    extern template void UnitTest::checkType<long>();
    extern template void UnitTest::checkType<long long>();
    extern template void UnitTest::checkType<unsigned short>();
    extern template void UnitTest::checkType<unsigned>();
    extern template void UnitTest::checkType<unsigned long>();
    extern template void UnitTest::checkType<unsigned long long>();
    extern template void UnitTest::checkType<bool>();
    extern template void UnitTest::checkType<float>();
    extern template void UnitTest::checkType<double>();
    extern template void UnitTest::checkType<long double>();
    extern template void UnitTest::checkType<std::complex<float>>();
    extern template void UnitTest::checkType<std::complex<double>>();
    extern template void UnitTest::checkType<std::complex<long double>>();

  } // namespace Simd
} // namespace Dune

#endif // DUNE_COMMON_SIMD_TEST_STANDARDTEST_HH

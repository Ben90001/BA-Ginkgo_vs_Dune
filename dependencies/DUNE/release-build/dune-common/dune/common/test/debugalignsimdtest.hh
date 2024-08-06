// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from debugalignsimdtest.hh.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#ifndef DUNE_COMMON_TEST_DEBUGALIGNSIMDTEST_HH
#define DUNE_COMMON_TEST_DEBUGALIGNSIMDTEST_HH

#include <dune/common/debugalign.hh>
#include <dune/common/simd/test.hh>

namespace Dune {
  namespace Simd {

    extern template void UnitTest::checkType<AlignedNumber<double> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<AlignedNumber<double> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<AlignedNumber<double> >();
    extern template void UnitTest::checkType<AlignedNumber<bool> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<AlignedNumber<bool> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<AlignedNumber<bool> >();

  } //namespace Simd
} // namespace Dune

#endif // DUNE_COMMON_TEST_DEBUGALIGNSIMDTEST_HH

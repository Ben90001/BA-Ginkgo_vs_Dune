// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from looptest_vector.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#include <config.h>

#include <dune/common/simd/test/looptest.hh>

namespace Dune {
  namespace Simd {

    template void UnitTest::checkType<LoopSIMD<double, 5> >();
    template void UnitTest::checkType<LoopSIMD<double, 5, 64> >();
    template void UnitTest::checkType<LoopSIMD<LoopSIMD<double, 2>, 5> >();

  } //namespace Simd
} // namespace Dune

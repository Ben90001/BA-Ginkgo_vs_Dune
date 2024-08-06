// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from vctest_simdmaskarray.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#include <config.h>

#include <dune/common/simd/test/vcarraytest.hh>

namespace Dune {
  namespace Simd {

    template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdMaskArray<std::uint16_t, ::lanes> >();

  } // namespace Simd
} // namespace Dune

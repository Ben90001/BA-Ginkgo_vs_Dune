// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from debugalignsimd.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#include <config.h>

#include <dune/common/debugalign.hh>
#include <dune/common/simd/test.hh>
#include <dune/common/test/debugalignsimdtest.hh>

namespace Dune {
  namespace Simd {

    template void UnitTest::checkBinaryOpsVectorScalar<AlignedNumber<bool> >();

  } //namespace Simd
} // namespace Dune

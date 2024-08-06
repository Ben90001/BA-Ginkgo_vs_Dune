// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from vcarraytest.hh.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#ifndef DUNE_COMMON_SIMD_TEST_VCTEST_HH
#define DUNE_COMMON_SIMD_TEST_VCTEST_HH

#if HAVE_VC

#include <cstddef>
#include <cstdint> // for std::[u]int#_t as substituted

#include <dune/common/simd/test.hh>
#include <dune/common/simd/vc.hh>

constexpr std::size_t lanes = 4;

namespace Dune {
  namespace Simd {

    extern template void
    UnitTest::checkType<Vc::SimdArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdMaskArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdMaskArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdMaskArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdMaskArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdMaskArray<std::int16_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdMaskArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdMaskArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdMaskArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdMaskArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdMaskArray<std::uint16_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdMaskArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdMaskArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdMaskArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdMaskArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdMaskArray<std::int32_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdMaskArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdMaskArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdMaskArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdMaskArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdMaskArray<std::uint32_t, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdArray<float, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdMaskArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdMaskArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdMaskArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdMaskArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdArray<float, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdMaskArray<float, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdArray<double, ::lanes> >();
    extern template void
    UnitTest::checkType<Vc::SimdMaskArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsScalarVector<Vc::SimdMaskArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorScalar<Vc::SimdMaskArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsProxyVector<Vc::SimdMaskArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdArray<double, ::lanes> >();
    extern template void
    UnitTest::checkBinaryOpsVectorProxy<Vc::SimdMaskArray<double, ::lanes> >();

  } // namespace Simd
} // namespace Dune

#endif // HAVE_VC
#endif // DUNE_COMMON_SIMD_TEST_VCTEST_HH

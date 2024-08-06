// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from vcvectortest.hh.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#ifndef DUNE_COMMON_SIMD_TEST_VCTEST_HH
#define DUNE_COMMON_SIMD_TEST_VCTEST_HH

#if HAVE_VC

#include <cstdint>

#include <dune/common/simd/test.hh>
#include <dune/common/simd/vc.hh>
#include <dune/common/typelist.hh>

namespace Dune {
  namespace Simd {

    extern template void UnitTest::checkType<Vc::Vector<std::int16_t> >();
    extern template void UnitTest::checkType<Vc::Mask<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Vector<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Mask<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Vector<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Mask<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Vector<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Mask<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Vector<std::int16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Mask<std::int16_t> >();
    extern template void UnitTest::checkType<Vc::Vector<std::uint16_t> >();
    extern template void UnitTest::checkType<Vc::Mask<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Vector<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Mask<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Vector<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Mask<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Vector<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Mask<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Vector<std::uint16_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Mask<std::uint16_t> >();
    extern template void UnitTest::checkType<Vc::Vector<std::int32_t> >();
    extern template void UnitTest::checkType<Vc::Mask<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Vector<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Mask<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Vector<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Mask<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Vector<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Mask<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Vector<std::int32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Mask<std::int32_t> >();
    extern template void UnitTest::checkType<Vc::Vector<std::uint32_t> >();
    extern template void UnitTest::checkType<Vc::Mask<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Vector<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Mask<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Vector<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Mask<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Vector<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Mask<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Vector<std::uint32_t> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Mask<std::uint32_t> >();
    extern template void UnitTest::checkType<Vc::Vector<float> >();
    extern template void UnitTest::checkType<Vc::Mask<float> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Vector<float> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Mask<float> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Vector<float> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Mask<float> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Vector<float> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Mask<float> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Vector<float> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Mask<float> >();
    extern template void UnitTest::checkType<Vc::Vector<double> >();
    extern template void UnitTest::checkType<Vc::Mask<double> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Vector<double> >();
    extern template void UnitTest::checkBinaryOpsScalarVector<Vc::Mask<double> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Vector<double> >();
    extern template void UnitTest::checkBinaryOpsVectorScalar<Vc::Mask<double> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Vector<double> >();
    extern template void UnitTest::checkBinaryOpsProxyVector<Vc::Mask<double> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Vector<double> >();
    extern template void UnitTest::checkBinaryOpsVectorProxy<Vc::Mask<double> >();

  } // namespace Simd
} // namespace Dune

#endif // HAVE_VC
#endif // DUNE_COMMON_SIMD_TEST_VCTEST_HH

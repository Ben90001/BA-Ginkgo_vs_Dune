// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from vcarraytest.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#if HAVE_CONFIG_H
#include "config.h"
#endif

#if !HAVE_VC
#error Inconsistent buildsystem.  This program should not be built in the \
  absence of Vc.
#endif

#include <cstddef>
#include <cstdlib>
#include <type_traits>

#include <dune/common/simd/test.hh>
#include <dune/common/simd/test/vcarraytest.hh>
#include <dune/common/simd/vc.hh>
#include <dune/common/typelist.hh>

template<class T> struct RebindAccept : std::false_type {};
template<>
struct RebindAccept<Vc::SimdArray<std::int16_t, ::lanes> >     : std::true_type {};
template<>
struct RebindAccept<Vc::SimdMaskArray<std::int16_t, ::lanes> > : std::true_type {};
template<>
struct RebindAccept<Vc::SimdArray<std::uint16_t, ::lanes> >     : std::true_type {};
template<>
struct RebindAccept<Vc::SimdMaskArray<std::uint16_t, ::lanes> > : std::true_type {};
template<>
struct RebindAccept<Vc::SimdArray<std::int32_t, ::lanes> >     : std::true_type {};
template<>
struct RebindAccept<Vc::SimdMaskArray<std::int32_t, ::lanes> > : std::true_type {};
template<>
struct RebindAccept<Vc::SimdArray<std::uint32_t, ::lanes> >     : std::true_type {};
template<>
struct RebindAccept<Vc::SimdMaskArray<std::uint32_t, ::lanes> > : std::true_type {};
template<>
struct RebindAccept<Vc::SimdArray<float, ::lanes> >     : std::true_type {};
template<>
struct RebindAccept<Vc::SimdMaskArray<float, ::lanes> > : std::true_type {};
template<>
struct RebindAccept<Vc::SimdArray<double, ::lanes> >     : std::true_type {};
template<>
struct RebindAccept<Vc::SimdMaskArray<double, ::lanes> > : std::true_type {};

using Rebinds = Dune::TypeList<
  std::int16_t,
  std::uint16_t,
  std::int32_t,
  std::uint32_t,
  float,
  double,
  bool,
  std::size_t>;

int main()
{
  using Vc::Vector;
  using Vc::SimdArray;

  Dune::Simd::UnitTest test;

  test.check<SimdArray<std::int16_t, ::lanes>,
             Rebinds, Dune::Simd::IsLoop, RebindAccept>();
  test.check<SimdArray<std::uint16_t, ::lanes>,
             Rebinds, Dune::Simd::IsLoop, RebindAccept>();
  test.check<SimdArray<std::int32_t, ::lanes>,
             Rebinds, Dune::Simd::IsLoop, RebindAccept>();
  test.check<SimdArray<std::uint32_t, ::lanes>,
             Rebinds, Dune::Simd::IsLoop, RebindAccept>();
  test.check<SimdArray<float, ::lanes>,
             Rebinds, Dune::Simd::IsLoop, RebindAccept>();
  test.check<SimdArray<double, ::lanes>,
             Rebinds, Dune::Simd::IsLoop, RebindAccept>();

  return test.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}

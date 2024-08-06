// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from vcvectortest.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

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
#include <dune/common/simd/test/vcvectortest.hh>
#include <dune/common/simd/vc.hh>
#include <dune/common/typelist.hh>

template<class> struct RebindAccept : std::false_type  {};
template<> struct RebindAccept<Vc::Vector<std::int16_t> > : std::true_type {};
template<> struct RebindAccept<Vc::Mask<std::int16_t> >   : std::true_type {};
template<> struct RebindAccept<Vc::Vector<std::uint16_t> > : std::true_type {};
template<> struct RebindAccept<Vc::Mask<std::uint16_t> >   : std::true_type {};
template<> struct RebindAccept<Vc::Vector<std::int32_t> > : std::true_type {};
template<> struct RebindAccept<Vc::Mask<std::int32_t> >   : std::true_type {};
template<> struct RebindAccept<Vc::Vector<std::uint32_t> > : std::true_type {};
template<> struct RebindAccept<Vc::Mask<std::uint32_t> >   : std::true_type {};
template<> struct RebindAccept<Vc::Vector<float> > : std::true_type {};
template<> struct RebindAccept<Vc::Mask<float> >   : std::true_type {};
template<> struct RebindAccept<Vc::Vector<double> > : std::true_type {};
template<> struct RebindAccept<Vc::Mask<double> >   : std::true_type {};

// ignore rebinds to LoopSIMD as well as Vc::SimdArray
template<class T> struct Prune : Dune::Simd::IsLoop<T>  {};
template<class T, std::size_t n, class V, std::size_t m>
struct Prune<Vc::SimdArray<T, n, V, m> >     : std::true_type {};

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

  test.check<Vector<std::int16_t>, Rebinds, Prune, RebindAccept>();
  test.check<Vector<std::uint16_t>, Rebinds, Prune, RebindAccept>();
  test.check<Vector<std::int32_t>, Rebinds, Prune, RebindAccept>();
  test.check<Vector<std::uint32_t>, Rebinds, Prune, RebindAccept>();
  test.check<Vector<float>, Rebinds, Prune, RebindAccept>();
  test.check<Vector<double>, Rebinds, Prune, RebindAccept>();

  return test.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}

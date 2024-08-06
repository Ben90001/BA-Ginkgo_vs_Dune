// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from looptest.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <cstdlib>
#include <type_traits>

#include <dune/common/simd/loop.hh>
#include <dune/common/simd/test.hh>
#include <dune/common/simd/test/looptest.hh>
#include <dune/common/typetraits.hh>

template<class> struct RebindAccept : std::false_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<char, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<char, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<unsigned char, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<unsigned char, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<signed char, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<signed char, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<short, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<short, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<int, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<int, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<long, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<long, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<long long, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<long long, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<unsigned short, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<unsigned short, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<unsigned, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<unsigned, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<unsigned long, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<unsigned long, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<unsigned long long, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<unsigned long long, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<bool, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<bool, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<float, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<float, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<double, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<double, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<long double, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<long double, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<std::complex<float>, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<std::complex<float>, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<std::complex<double>, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<std::complex<double>, 2, A1>, 5, A2> > : std::true_type {};
template<std::size_t A>
struct RebindAccept<Dune::LoopSIMD<std::complex<long double>, 5, A> > : std::true_type {};
template<std::size_t A1, std::size_t A2>
struct RebindAccept<Dune::LoopSIMD<Dune::LoopSIMD<std::complex<long double>, 2, A1>, 5, A2> > : std::true_type {};

using Rebinds = Dune::Simd::RebindList<
  char,
  unsigned char,
  signed char,
  short,
  int,
  long,
  long long,
  unsigned short,
  unsigned,
  unsigned long,
  unsigned long long,
  bool,
  float,
  double,
  long double,
  std::complex<float>,
  std::complex<double>,
  std::complex<long double>,
  Dune::Simd::EndMark>;

int main()
{
  Dune::Simd::UnitTest test;

  test.check<Dune::LoopSIMD<char, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<char, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<char, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned char, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned char, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<unsigned char, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<signed char, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<signed char, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<signed char, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<short, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<short, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<short, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<int, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<int, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<int, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<long, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<long, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<long, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<long long, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<long long, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<long long, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned short, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned short, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<unsigned short, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<unsigned, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned long, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned long, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<unsigned long, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned long long, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<unsigned long long, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<unsigned long long, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<bool, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<bool, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<bool, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<float, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<float, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<float, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<double, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<double, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<double, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<long double, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<long double, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<long double, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<std::complex<float>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<std::complex<float>, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<std::complex<float>, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<std::complex<double>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<std::complex<double>, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<std::complex<double>, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<std::complex<long double>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<std::complex<long double>, 5, 64>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::LoopSIMD<Dune::LoopSIMD<std::complex<long double>, 2>, 5>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();

  return test.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}

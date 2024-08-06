// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from standardtest.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <cstdlib>
#include <type_traits>

#include <dune/common/typetraits.hh>
#include <dune/common/simd/test.hh>
#include <dune/common/simd/test/standardtest.hh>

template<class> struct RebindAccept : std::false_type {};
template<> struct RebindAccept<char> : std::true_type {};
template<> struct RebindAccept<unsigned char> : std::true_type {};
template<> struct RebindAccept<signed char> : std::true_type {};
template<> struct RebindAccept<short> : std::true_type {};
template<> struct RebindAccept<int> : std::true_type {};
template<> struct RebindAccept<long> : std::true_type {};
template<> struct RebindAccept<long long> : std::true_type {};
template<> struct RebindAccept<unsigned short> : std::true_type {};
template<> struct RebindAccept<unsigned> : std::true_type {};
template<> struct RebindAccept<unsigned long> : std::true_type {};
template<> struct RebindAccept<unsigned long long> : std::true_type {};
template<> struct RebindAccept<bool> : std::true_type {};
template<> struct RebindAccept<float> : std::true_type {};
template<> struct RebindAccept<double> : std::true_type {};
template<> struct RebindAccept<long double> : std::true_type {};
template<> struct RebindAccept<std::complex<float>> : std::true_type {};
template<> struct RebindAccept<std::complex<double>> : std::true_type {};
template<> struct RebindAccept<std::complex<long double>> : std::true_type {};

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

  test.check<char, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<unsigned char, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<signed char, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<short, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<int, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<long, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<long long, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<unsigned short, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<unsigned, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<unsigned long, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<unsigned long long, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<bool, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<float, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<double, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<long double, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<std::complex<float>, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<std::complex<double>, Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<std::complex<long double>, Rebinds, Dune::AlwaysFalse, RebindAccept>();

  return test.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}

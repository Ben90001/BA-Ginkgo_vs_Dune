// SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
// SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception
// generated from debugalignsimdtest.cc.in by cmake -*- buffer-read-only:t -*- vim: set readonly:

#include <config.h>

#include <cstdlib>
#include <type_traits>

#include <dune/common/typetraits.hh>
#include <dune/common/debugalign.hh>
#include <dune/common/parallel/mpihelper.hh>
#include <dune/common/simd/test.hh>
#include <dune/common/test/debugalignsimdtest.hh>

template<class> struct RebindAccept : std::false_type {};
template<>
struct RebindAccept<Dune::AlignedNumber<double> > : std::true_type {};
template<>
struct RebindAccept<Dune::AlignedNumber<bool> > : std::true_type {};

int main(int argc, char **argv)
{
  Dune::MPIHelper::instance(argc, argv);

  Dune::Simd::UnitTest test;

  using Rebinds = Dune::Simd::RebindList<
    double,
    bool,
    Dune::Simd::EndMark>;

  test.check<Dune::AlignedNumber<double>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();
  test.check<Dune::AlignedNumber<bool>,
             Rebinds, Dune::AlwaysFalse, RebindAccept>();

  return test.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}

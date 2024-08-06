# SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
# SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception

from setuptools import setup, find_namespace_packages

pkg = 'pip>=21.a portalocker numpy wheel setuptools>=41 jinja2'.replace(';',' ').split(' ')

# convert cmake bool to python bool
def cmake_to_bool(str):
  if str in ['1', 'ON', 'YES', 'TRUE', 'Y']:
    return True
  else:
    return False

# if MPI is found dune-common will be linked to MPI
# in that case we require mpi4py for MPI support from the Python side
# This will not install mpi4py when installing in build-isolation but
# will install it into the (internal) venv during a source build.
# The case of a package installation is taken care of in
# `python/dune/common/__init__.py'.
if cmake_to_bool("TRUE") and not cmake_to_bool(""):
  pkg += ['mpi4py']

setup(name="dune-common",
    # only add 'dune' here in dune-common other packages shouldn't add file # directly to 'dune'
    packages=find_namespace_packages(include=['dune','dune.*']),
    description="Basis infrastructure for all Dune modules",
    version="2.9.1",
    author="The Dune Core developers",
    author_email="dune-devel@lists.dune-project.org",
    zip_safe = 0,
    package_data = {'': ['*.so']},
    install_requires = pkg,
    include_package_data=True,
  )

# SPDX-FileCopyrightInfo: Copyright (C) DUNE Project contributors, see file LICENSE.md in module root
# SPDX-License-Identifier: LicenseRef-GPL-2.0-only-with-DUNE-exception

from setuptools import setup, find_namespace_packages

pkg = ' dune-common'.replace(';',' ').split(' ')

setup(name="dune-istl",
    packages=find_namespace_packages(include=['dune.*']),
    description="Iterative solver template library which provides generic sparse matrix/vector classes and a variety of solvers based on these classes",
    version="2.9.0",
    author="The Dune Core developers",
    author_email="dune-devel@lists.dune-project.org",
    zip_safe = 0,
    package_data = {'': ['*.so']},
    install_requires = pkg,
    include_package_data=True,
  )

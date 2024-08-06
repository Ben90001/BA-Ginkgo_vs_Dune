/* config.h.  Generated from config_collected.h.cmake by CMake.
   It was generated from config_collected.h.cmake which in turn is generated automatically
   from the config.h.cmake files of modules this module depends on. */

/* Define to 1 if you have module dune-istl available */
#define HAVE_DUNE_ISTL 1


/* Define to 1 if you have module dune-common available */
#define HAVE_DUNE_COMMON 1


/* begin private */
/* Define to the version of dune-common */
#define DUNE_COMMON_VERSION "2.9.1"

/* Define to the major version of dune-common */
#define DUNE_COMMON_VERSION_MAJOR 2

/* Define to the minor version of dune-common */
#define DUNE_COMMON_VERSION_MINOR 9

/* Define to the revision of dune-common */
#define DUNE_COMMON_VERSION_REVISION 1

/* Standard debug streams with a level below will collapse to doing nothing */
#define DUNE_MINIMAL_DEBUG_LEVEL 4

/* does the standard library provide experimental::make_array() ? */
#define DUNE_HAVE_CXX_EXPERIMENTAL_MAKE_ARRAY 1

/* does the standard library provide experimental::is_detected ? */
#define DUNE_HAVE_CXX_EXPERIMENTAL_IS_DETECTED 1

/* does the language support lambdas in unevaluated contexts ? */
/* #undef DUNE_HAVE_CXX_UNEVALUATED_CONTEXT_LAMBDA */

/* does the standard library provide identity ? */
/* #undef DUNE_HAVE_CXX_STD_IDENTITY */

/* Define if you have a BLAS library. */
#define HAVE_BLAS 1

/* Define if you have LAPACK library. */
#define HAVE_LAPACK 1

/* Define if you have the MPI library.  */
#define HAVE_MPI ENABLE_MPI

/* Deactivate cxx bindings for MPI */
#if defined(HAVE_MPI) && HAVE_MPI
#define MPICH_SKIP_MPICXX 1
#define OMPI_SKIP_MPICXX 1
#define MPI_NO_CPPBIND 1
#define MPIPP_H
#define _MPICC_H
#endif

/* Define if you have the GNU GMP library. The value should be ENABLE_GMP
   to facilitate activating and deactivating GMP using compile flags. */
#define HAVE_GMP ENABLE_GMP

/* Define if you have the GCC Quad-Precision library. The value should be ENABLE_QUADMATH
   to facilitate activating and deactivating QuadMath using compile flags. */
#define HAVE_QUADMATH ENABLE_QUADMATH

/* Define if you have the Vc library. The value should be ENABLE_VC
   to facilitate activating and deactivating Vc using compile flags. */
/* #undef HAVE_VC */

/* Define to 1 if you have the Threading Building Blocks (TBB) library */
#define HAVE_TBB 1




/* old feature support macros which were tested until 2.8, kept around for one more release */
#define HAS_ATTRIBUTE_DEPRECATED 0
#define HAS_ATTRIBUTE_DEPRECATED_MSG 0
#define HAS_ATTRIBUTE_UNUSED 0

/* Define to ENABLE_UMFPACK if the UMFPack library is available */
#define HAVE_UMFPACK ENABLE_SUITESPARSE

/* Define to ENABLE_SUITESPARSE if the SuiteSparse library is available */
#define HAVE_SUITESPARSE ENABLE_SUITESPARSE

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's AMD library is available */
/* #undef HAVE_SUITESPARSE_AMD */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's BTF library is available */
/* #undef HAVE_SUITESPARSE_BTF */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's CAMD library is available */
/* #undef HAVE_SUITESPARSE_CAMD */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's CCOLAMD library is available */
/* #undef HAVE_SUITESPARSE_CCOLAMD */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's CHOLMOD library is available */
#define HAVE_SUITESPARSE_CHOLMOD ENABLE_SUITESPARSE

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's COLAMD library is available */
/* #undef HAVE_SUITESPARSE_COLAMD */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's CXSPARSE library is available */
/* #undef HAVE_SUITESPARSE_CXSPARSE */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's KLU library is available */
/* #undef HAVE_SUITESPARSE_KLU */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's LDL library is available */
#define HAVE_SUITESPARSE_LDL ENABLE_SUITESPARSE

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's RBIO library is available */
/* #undef HAVE_SUITESPARSE_RBIO */

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's SPQR library is available
   and if it's version is at least 4.3 */
#define HAVE_SUITESPARSE_SPQR ENABLE_SUITESPARSE

/* Define to ENABLE_SUITESPARSE if the SuiteSparse's UMFPACK library is available */
#define HAVE_SUITESPARSE_UMFPACK ENABLE_SUITESPARSE

/* Define to 1 if METIS is available */
#define HAVE_METIS 1

/* Define to 1 if the Scotch replacement for METIS is used. */
/* #undef HAVE_SCOTCH_METIS */

/* Define to 1 if you have the ParMETIS library. */
/* #undef HAVE_PARMETIS */

/* Define to 1 if the PTScotch replacement for ParMETIS is used. */
/* #undef HAVE_PTSCOTCH_PARMETIS */

/* Define to 1 if PT-Scotch is available */
/* #undef HAVE_PTSCOTCH */

/* Used to call lapack functions */
#define LAPACK_NEEDS_UNDERLINE



/* begin dune-istl
   put the definitions for config.h specific to
   your project here. Everything above will be
   overwritten
*/

/* begin private */
/* Name of package */
#define PACKAGE "dune-istl"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "dune-devel@lists.dune-project.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "dune-istl"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "dune-istl 2.9.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "dune-istl"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.9.0"

/* end private */

/* Define to ENABLE_SUPERLU if the SuperLU library is available */
/* #undef HAVE_SUPERLU */

/* Define to the integer type that SuperLU was compiled for
   See e.g. what int_t is defined to in slu_sdefs.h */
#define SUPERLU_INT_TYPE int

/* Define to ENABLE_ARPACKPP if the ARPACK++ library is available */
/* #undef HAVE_ARPACKPP */

/* Define to the version of dune-istl */
#define DUNE_ISTL_VERSION "2.9.0"

/* Define to the major version of dune-istl */
#define DUNE_ISTL_VERSION_MAJOR 2

/* Define to the minor version of dune-istl */
#define DUNE_ISTL_VERSION_MINOR 9

/* Define to the revision of dune-istl */
#define DUNE_ISTL_VERSION_REVISION 0

/* Enable/Disable the backwards compatibility of the category enum/method in dune-istl solvers, preconditioner, etc. */
#define DUNE_ISTL_SUPPORT_OLD_CATEGORY_INTERFACE 1

/* end dune-istl
   Everything below here will be overwritten
*/

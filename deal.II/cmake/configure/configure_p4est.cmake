#####
##
## Copyright (C) 2012 by the deal.II authors
##
## This file is part of the deal.II library.
##
## <TODO: Full License information>
## This file is dual licensed under QPL 1.0 and LGPL 2.1 or any later
## version of the LGPL license.
##
## Author: Matthias Maier <matthias.maier@iwr.uni-heidelberg.de>
##
#####

#
# Configuration for the p4est and sc libraries:
#


SET(FEATURE_P4EST_DEPENDS DEAL_II_WITH_MPI)


MACRO(FEATURE_P4EST_FIND_EXTERNAL var)
  FIND_PACKAGE(P4EST)

  IF(P4EST_FOUND)
    #
    # Check whether p4est supports mpi:
    #
    IF(NOT P4EST_WITH_MPI)
      MESSAGE(WARNING "\n"
        "Could not find a sufficient p4est installation: "
        "P4est has to be configured with MPI support enabled.\n\n"
        )
    ELSE()
      SET(${var} TRUE)
    ENDIF()
  ENDIF()
ENDMACRO()


MACRO(FEATURE_P4EST_ERROR_MESSAGE)
  MESSAGE(FATAL_ERROR "\n"
    "Could not find the p4est and sc libraries!\n"
    "Please ensure that the libraries are installed on your computer.\n"
    "If the libraries are not at a default location, either provide some hints\n"
    "for the autodetection:\n"
    "    $ P4EST_DIR=\"...\" cmake <...>\n"
    "    $ cmake -DP4EST_DIR=\"...\" <...>\n"
    "or set the relevant variables by hand in ccmake.\n"
    )
ENDMACRO()


CONFIGURE_FEATURE(P4EST)

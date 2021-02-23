AC_INIT([RcppChoose],[0.0.1])

# Find the C++ compiler and compiler flags used by R.
: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}"; then
    echo "could not determine R_HOME"
      exit 1
fi
CXX=`"${R_HOME}/bin/R" CMD config CXX`
CXXFLAGS=`"${R_HOME}/bin/R" CMD config CXXFLAGS`
CPPFLAGS=`"${R_HOME}/bin/R" CMD config CPPFLAGS`
AC_LANG(C++)
AC_PROG_CPP

# Custom flags for Choose library
CHOOSE_DIR="${ac_abs_confdir}/../libChoose/"
CHOOSE_INC=-I"${CHOOSE_DIR}"
CHOOSE_LIB="-L${CHOOSE_DIR} -lChoose"

# Write the flags into the src/Makevars file.
# PKG_CPPFLAGS = @PKG_CPPFLAGS@ @CHOOSE_INC@
AC_SUBST([PKG_CPPFLAGS], ["${PKG_CPPFLAGS} ${CXXFLAGS} ${CHOOSE_INC}"])
# PKG_LIBS = @PKG_LIBS@ @CHOOSE_LIB@
AC_SUBST([PKG_LIBS], ["${PKG_LIBS} ${CHOOSE_LIB}"])
# Destination Makefile
AC_CONFIG_FILES([RcppChoose/src/Makevars])
AC_OUTPUT

echo "
--------------------------------------------------
  Configuration for ${PACKAGE_NAME} ${PACKAGE_VERSION}

  cppflags: ${CPPFLAGS} ${PKG_CPPFLAGS}
  libs:     ${PKG_LIBS}
--------------------------------------------------
"

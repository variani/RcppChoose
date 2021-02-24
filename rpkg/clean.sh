#!/bin/sh

# autoconf output files
rm -f config.*
rm -f src/Makevars
rm -rf autom4te.cache

# Rcpp compilation results
rm -f RcppChoose/src/*.o
rm -f RcppChoose/src/*.so
rm -rf RcppChoose/src/RcppExports.*


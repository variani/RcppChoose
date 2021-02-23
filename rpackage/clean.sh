#!/bin/sh

# autoconf output files
rm -f config.*
rm -f src/Makevars
rm -rf autom4te.cache

# Rcpp compilation results
rm -f src/*.o
rm -rf src/RcppExports.*


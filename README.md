
<!-- README.md is generated from README.Rmd. Please edit that file -->

# RcppChoose

<!-- badges: start -->

<!-- badges: end -->

RcppChoose is an example of project that combines two parts, C++ code
([libChoose/](libChoose/)) and R package ([rpackage/](rpackage/)).

## Install

    # 1. compile the c++ library 
    # - output: libChoose/libChoose.a
    pushd libChoose/
    make
    popd
    
    # 2. prepare Makefile for R package
    # - output: rpkg/RcppChoose/src/Makevars
    pushd rpkg
    autoconf
    ./configure
    popd
    
    # 3. check R package is ready to use 
    Rscript --slave -e "devtools::load_all('rpkg/RcppChoose')"

## Usage

``` r
devtools::load_all("rpkg/RcppChoose")
#> Loading RcppChoose
```

## Example

This is a basic example which shows you how to choose `k` out of `n`
numbers.

``` r
library(RcppChoose)

# 1. choose: base R vs. RcppChoose implementation
# 1a. choose(10, 5)
choose(10, 5)
#> [1] 252
rcpp_choose(10, 5)
#> [1] 252
# 1b. choose(40, 20)
choose(40, 20)
#> [1] 137846528820
rcpp_choose(40, 20)
#> [1] 106285226

# 100 samples of sets of size k = 500 out of n = 1000
rcpp_nchoosek_sample(1000, 500, 100)
#> [1] 100
```

## Notes

Main references that explain how to link external C++ libraries to the
R/Rcpp package.

  - Blog post [An Autoconf Primer for R Package
    Authors](https://unconj.ca/blog/an-autoconf-primer-for-r-package-authors.html).
  - Minimal `Makevars.in` example in
    [SO](https://stackoverflow.com/a/56884883).
  - Example
    [rbgen](https://enkre.net/cgi-bin/code/bgen/doc/trunk/doc/wiki/rbgen.md)
    R package; see [blog
    posts](https://gavinband.github.io/biobank/bgen/2017/05/16/Getting_biobank_data_into_R.html).
  - The R official
    [manual](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Using-Makevars).

### Other notes

1.  `configure.ac` is included in the list of [known
    files](https://blog.r-hub.io/2020/05/20/rbuildignore/#standard-known-directory-and-files)
    relevant for the R package development. So adding `configure.ac` to
    `.Rbuildignore` will have no effect, and the R building/loading
    commands will execute `configure.ac`.

Here, this configuration file is separated from the source of R package
in the directory [rpkg/](rpkg/): [rpkg/configure.ac](rpkg/configure.ac)
and the R package directory [rpkg/RcppChoose/](rpkg/RcppChoose/).

2.  The compilation flag `-fPIC` is
    [necessary](https://stackoverflow.com/q/49503475) for building
    shared libraries. Ommiting this flag will lead to the following
    error.

<!-- end list -->

    /usr/bin/ld: RcppChoose/rpkg/../libChoose//libChoose.a(choose.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    RcppChoose/rpkg/../libChoose//libChoose.a: error adding symbols: Bad value
    collect2: error: ld returned 1 exit status
    /usr/share/R/share/make/shlib.mk:6: recipe for target 'RcppChoose.so' failed

3.  [SO](https://stackoverflow.com/a/31541868) on compilation of the
    shared library.

4.  [Notes](https://gallery.rcpp.org/articles/first-steps-with-C++11/)
    on using C++11 with [Rcpp](http://www.rcpp.org/).

> As even the current g++ version does of course support C++11 by
> default, one still needs to explicitly enable C++11 support which we
> can do here from R prior to compiling.

Here, we adress this issue by the line `CXX_STD = CXX11` in
[rpkg/RcppChoose/src/Makevars.in](rpkg/RcppChoose/src/Makevars.in) and
the flag `-std=c++11` in [libChoose/Makefile](libChoose/Makefile).

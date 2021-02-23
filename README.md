
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

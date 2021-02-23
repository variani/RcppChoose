
<!-- README.md is generated from README.Rmd. Please edit that file -->

# RcppChoose

<!-- badges: start -->

<!-- badges: end -->

RcppChoose is an example of project that combines two parts, C++ code
([libChoose/](libChoose/) and R package [rpackage/](rpackage/).

## Installation

``` r
library(devtools)
load_all("RcppChoose/rpackage/")
```

## Example

This is a basic example which shows you how to choose `k` out of `n` numbers.

``` r
library(RcppChoose)

rcpp_choose(40, 20)
#> [1] 106285226
rcpp_nchoosek_sample(1000, 500, 100)
#> [1] 100
```

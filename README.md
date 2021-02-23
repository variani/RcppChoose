
<!-- README.md is generated from README.Rmd. Please edit that file -->

# RcppChoose

<!-- badges: start -->

<!-- badges: end -->

RcppChoose is an example of project that combines two parts, C++ code
([libChoose/](libChoose/) and R package [rpackage/](rpackage/).

## Installation

``` r
devtools::load_all("rpackage/")
#> Loading RcppChoose
```

## Example

This is a basic example which shows you how to choose `k` out of `n`
numbers.

``` r
library(RcppChoose)

# choose: base R vs. RcppChoose implementation
choose(40, 20)
#> [1] 137846528820
rcpp_choose(40, 20)
#> [1] 106285226

# 100 samples of sets of size k = 500 out of n = 1000
rcpp_nchoosek_sample(1000, 500, 100)
#> [1] 100
```

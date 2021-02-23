#include <Rcpp.h>

#include "choose.hpp"

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
int rcpp_nchoosek_sample(int n, int k, int s)
{
  list<vector<int>> sets = nchoosek_sample(n, k, s);
  return sets.size();
}

// [[Rcpp::export]]
int rcpp_nchoosek_rec(int n, int k)
{
  list<vector<int>> sets = nchoosek_rec(n, k);
  return sets.size();
}

// [[Rcpp::export]]
int rcpp_choose (int n, int k)
{
  int ret = choose(n, k);
  return ret;
}


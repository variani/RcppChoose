#include "choose.hpp"

void _sample(int n, int k, vector<int> &l)
{
  unordered_set<int> sample;
  
  std::random_device seed;
  std::mt19937_64 gen(seed());

  for(int i = n - k; i < n; ++i) {
    std::uniform_int_distribution<int> distr(0, i);
    int s = distr(gen);

    if(sample.find(s) == sample.end()) {
      sample.insert(s);
    } else {
      sample.insert(i);
    }
  }

  // copy unordered set (sample) to output vector (l)
  for(unordered_set<int>::iterator it = sample.begin(); it != sample.end(); ++it) {
    l.push_back(*it);
  }
  // sort output vector (l)
  sort(l.begin(), l.end());
}

list<vector<int>> nchoosek_sample(int n, int k, int s)
{
  list<vector<int>> ll;

  for(int i = 0; i < s; ++i) {
    vector<int> sample;
    sample.reserve(k);
    _sample(n, k, sample);
    ll.push_back(sample);
  }

  return(ll);
}

//-------------------------------------------
// nchoosek_rec(n, k)
// - All combinations of k elements out of n 
//   by the recursive algorithm
//-------------------------------------------
void _nchoosek_rec(int size, int left, int index, 
  vector<int> &l, list<vector<int>> &ll)
{
  if(left == 0) { 
    ll.push_back(l);
    return;
  }
  
  for(int i = index; i < size; i++) {
    l.push_back(i);
    _nchoosek_rec(size, left - 1, i + 1, l, ll);
    l.pop_back();
  }
}

list<vector<int>> nchoosek_rec(int n, int k)
{
  list<vector<int>> ll;

  vector<int> l;   
  l.reserve(k);
  _nchoosek_rec(n, k, 0, l, ll);

  return ll;
}

//-----------------------
// choose(n, k)
//-----------------------
int choose(int n, int k)
{
  if(k == 0) return 1;

  if(k > n /2) return(choose(n, n - k));
  
  int res = 1;

  for(int i = 1; i <= k; ++i) {
    res *= n - i + 1;
    res /= i;
  }

  return res;
}

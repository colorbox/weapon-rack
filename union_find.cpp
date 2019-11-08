struct UnionFind {
  vector<int> par, rank;

  UnionFind(int n){
    par.resize(n+1);
    fill(par.begin(), par.end(), -1);
    rank.resize(n+1);
  }

  int root(int x){
    if(par[x] < 0){
      return x;
    }

    par[x] = root(par[x]);

    return par[x];
  }

  void unite(int x, int y){
    int rx=root(x);
    int ry=root(y);

    if(rx!=ry){
      if(rank[rx] >= rank[ry]){
        par[ry]=rx;

        if(rank[rx]==rank[ry]){
          rank[rx] += 1;          
        }
      }else{
        par[rx] = ry;
      }
    }
  }

  bool is_same(int x, int y){
    return root(x)==root(y);
  }

  int count(int x){
    return -par[root(x)];
  }
};


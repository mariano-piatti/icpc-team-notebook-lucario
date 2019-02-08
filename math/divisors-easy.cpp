vector <long long> divs(long long n){ //O(sqrt (n))
    vector <long long> res;
    for (long long i = 2; i*i <= n; i++){
        if (n % i == 0 ){
            res.pb(i);
            if(i*i != n){
                res.pb(n/i);
            }
        }
    }        
    return res;
}

//Muchos divisores
vector <int> divs[100];

void initdivs(int M){
    for(int i = 1; i < M; i++){
        for(int j = i; j < M; j+=i){
            divs[j].pb(i);   
        }
    }
}

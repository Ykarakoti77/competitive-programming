const int N = 4e4;
bool seive[N];
vector<int> primes;
void preprocess(){
	for(int i = 2; i < N; ++i){
		seive[i] = true;
	}
 
	for(int i = 2; i < N; ++i){
		if (seive[i]) {
			primes.push_back(i);
			for(long long j = i * 1LL * i; j < N; j += i){
				seive[j] = false;
			}
		}
	}
}
 
int cnt_fact(long long x){
	int ret = 0;
	for(auto e: primes){
		while((x % e) == 0){
			x /= e;
			++ret;
		}
		if (x < e)
			break;
	}
	if (x > 1)
		++ret;
	return ret;
}

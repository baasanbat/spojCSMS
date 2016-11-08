#include <iostream>
#include <cstring>
long long memo[26];
long long rec(int n) {
	if (n==1 || n==0) return 1;
	if (n == 2) return 2;
	if (memo[n] != -1) return memo[n];
	long long ret = 0ll;
	for (int i = 0; i < n; i++) 
		ret = 1ll*(ret + 1ll*rec(i)*rec(n-i-1));
	return memo[n] = ret;
}
int main(int argc, char *argv[]) {
	int n; std::cin >> n;
	memset(memo, -1, sizeof memo);
	std::cout << rec(n/2) << std::endl;
	return 0;
}

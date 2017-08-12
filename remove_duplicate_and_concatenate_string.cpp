#include<iostream>
#include<string>
using namespace std;
string concatenate_string(string a, string b){
	int hash[26] = {0};
	for(int i = 0; i < b.size(); ++i){
		hash[int(b[i] - 'a')] = 1;
	}
	string c = "";
	for(int i = 0; i < a.size(); ++i){
		if(hash[int(a[i] - 'a')]) hash[int(a[i] - 'a')] = 2;
		else
			c = c + a[i];
	}
	for(int i = 0; i < b.size(); ++i){
		if(hash[int(b[i]) - 'a'] == 2);
		else
			c = c + b[i];
	}
	return c;
}
int main()
{
	string a = "fiiwnvlefi";
	string b = "vnkjnvlaejfn";
	string c = concatenate_string(a, b);
	cout << c << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

string convert(int n){
	if(n <= 9){
		return to_string(n);
	}else{
		n -= 10;
		n += 65;
		char c = n;
		string temp(1,c);
		return temp;
	}
}

char next(char c){
	if(c == 'F'){
		return '0';
	}else if(c == '9'){
		return 'A';
	}else{
		int n = c;
		n++;
		return (char) n;
	}
}

char invert(char s){
	if(s == '0'){
		return 'F';
	}else if(s == '1'){
		return 'E';
	}else if(s == '2'){
		return 'D';
	}else if(s == '3'){
		return 'C';
	}else if(s == '4'){
		return 'B';
	}else if(s == '5'){
		return 'A';
	}else if(s == '6'){
		return '9';
	}else if(s == '7'){
		return '8';
	}else if(s == '8'){
		return '7';
	}else if(s == '9'){
		return '6';
	}else if(s == 'A'){
		return '5';
	}else if(s == 'B'){
		return '4';
	}else if(s == 'C'){
		return '3';
	}else if(s == 'D'){
		return '2';
	}else if(s == 'E'){
		return '1';
	}else if(s == 'F'){
		return '0';
	}
}

string to_hex(long long n){
	string ans = "";
	bool is_neg = false;
	if(n < 0){
		is_neg = true;
		n = -n;
	}
	int q = n/16;
	int r = n%16;
	while(1){
		ans = convert(r) + ans;
		if(q == 0) break;
		r = q%16;
		q = q/16;
	}
	while(ans.size() < 8){
		ans = "0" + ans;
	}
	if(is_neg){
		for(int i = 0; i < ans.size(); i++){
			ans[i] = invert(ans[i]);
		}
		int carry = 1;
		for(int i = ans.size()-1; i >= 0; i--){
			if(carry == 0) break;
			if(ans[i] == 'F'){
				ans[i] = next(ans[i]);
			}else{
				carry = 0;
				ans[i] = next(ans[i]);
			}
		}
	}
	return ans;
}


int main(){
	cout<<"Enter I or LI or SI or Q"<<endl;
	while(1){
		string s;
		cin>>s;
		if(s == "Q"){
			break;
		}else if(s == "I"){
			int inp;
			cin>>inp;
			string temp = to_hex(inp);
			cout<<temp<<endl;
		}else if(s == "LI"){
			int inp = INT_MAX;
			//cout<<hex<<inp<<endl;
			string temp = to_hex(inp);
			cout<<temp<<endl;
		}else if(s == "SI"){
			int inp = INT_MIN;
			//cout<<hex<<inp<<endl;
			string temp = to_hex(inp);
			cout<<temp<<endl;
		}
	}

	return 0;
}
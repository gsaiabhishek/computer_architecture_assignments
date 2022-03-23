#include <bits/stdc++.h>
using namespace std;

string convert(string s){
	if(s == "0000"){
		return "0";
	}else if(s == "0001"){
		return "1";
	}else if(s == "0010"){
		return "2";
	}else if(s == "0011"){
		return "3";
	}else if(s == "0100"){
		return "4";
	}else if(s == "0101"){
		return "5";
	}else if(s == "0110"){
		return "6";
	}else if(s == "0111"){
		return "7";
	}else if(s == "1000"){
		return "8";
	}else if(s == "1001"){
		return "9";
	}else if(s == "1010"){
		return "A";
	}else if(s == "1011"){
		return "B";
	}else if(s == "1100"){
		return "C";
	}else if(s == "1101"){
		return "D";
	}else if(s == "1110"){
		return "E";
	}else if(s == "1111"){
		return "F";
	}

}

string to_hex(string s){  // from binary
	string ans = "";
	for(int i = 0; i < s.size()/4; i++){
		string temp = "";
		temp.push_back(s[31-4*i-3]);
		temp.push_back(s[31-4*i-2]);
		temp.push_back(s[31-4*i-1]);
		temp.push_back(s[31-4*i-0]);
		ans = convert(temp) + ans;
	}
	return ans;
}

string to_binary(int e){  // from int
	string ans = "";
	int q,r;
	q = e;
	while(1){
		if(q == 0) break;
		r = q%2;
		q = q/2;
		ans = to_string(r) + ans;
	}
	while(ans.size() < 8){
		ans = "0" + ans;
	}
	return ans;
}

string fp(double f){
	int count = 0;
	string ans1 = "0", ans2 ="", ans3 ="";
	if(f < 0){
		f = -f;
		ans1 = "1";
	}
	while(f < 1 || f >=2){
		if(f < 1){
			f *= 2;
			count--;
		}else if(f >= 2){
			f /= 2;
			count++;
		}
	}
	int e = 127+count;
	ans2 = to_binary(e);
	f -= 1;
	for(int i = 0; i < 23; i++){
		f *= 2;
		int temp = f;
		char c = f+'0';
		ans3.push_back(c);
		if(f >= 1) f -= 1;
	}
	return ans1+ans2+ans3;
}


int main(){
	cout<<"Enter F or LI or SP or SI or Q"<<endl;
	while(1){
		string s;
		cin>>s;
		if(s == "F"){
			float f;
			cin>>f;
			if(f == 0){
				cout<<"00000000"<<endl;
			}else{
				string ans = fp(f);
				ans = to_hex(ans);
				// unsigned int* p = (unsigned int *) &f;
				// unsigned int p1 = *p;
				// cout<<hex<<p1<<endl;
				cout<<ans<<endl;
			}
		}else if(s == "LI"){
			string ans = "01111111011111111111111111111111";
			ans = to_hex(ans);
			cout<<ans<<endl;
		}else if(s == "SI"){
			string ans = "01001011100000000000000000000000";
			ans = to_hex(ans);
			cout<<ans<<endl;
		}else if(s == "SP"){
			string ans = "00000000000000000000000000000001";
			ans = to_hex(ans);
			cout<<ans<<endl;
		}else if(s == "Q"){
			break;
		}
	}



}
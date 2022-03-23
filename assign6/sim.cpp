#include <bits/stdc++.h>
using namespace std;

int strtobin(string s){ // string to binary
	int n = s.size();
	int sum = 0;
	int val = 1;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == '1'){
			sum += val;
			val = 2*val;
		}else{
			val = 2*val;
		}
	}
	return sum;
}

int main(){
	int m;
	int n;
	int k = 1;
	int no_of_iterations;
	//int no_of_iterations = 100;
	cout<<"input m, n, no_of_iterations:"<<endl;
	cin>>m>>n>>no_of_iterations;
	int storage = (1 << (m+k));
	int max_state = (1 << n);
	int diff_state = max_state/2; // <= diff_state implies that FSM outputs Taken
	int bpb[storage];
	fill_n(bpb, storage, max_state);
	vector<int> predict, real, states;
	vector<string> history_string;
	string history(m, '0');
	int index;

	cout<<endl;
	cout<<"input 1 for print history(m bits) for all iterations, else 0"<<endl;
	int want_history;
	cin>>want_history;

	if(want_history && m == 0){
		cout<<"m = 0, come on!"<<endl;
	}

	int t3 = 0;
	int t0 = no_of_iterations;
	int t1, t2;
	chalo:
		t1 = t0%8;
	branch:
		index = strtobin(history+"0");
		states.push_back(bpb[index]);
		if(want_history && m > 0) history_string.push_back(history);
		if(bpb[index] <= diff_state){
			predict.push_back(1);
		}else{
			predict.push_back(0);
		}
		if(t1 > 2){//bgt branch - 0
			real.push_back(1);
			if(m > 0){
				history = history.substr(1);
				history.push_back('1');
			}
			if(bpb[index] != 1){
				bpb[index]--;
			}
			goto here;
		}else{
			real.push_back(0);
			if(m > 0){
				history = history.substr(1);
				history.push_back('0');
			}
			if(bpb[index] != max_state){
				bpb[index]++;
			}
		}
		t2 = 4*t0;
		t3 = t3 + t2;
		goto join;
	here:
		t2 = 2*t0;
		t3 = t3-2;
	join:
		t0 = t0 - 1;
		if(t0 != 0){ // bnez branch - 1
			if(m > 0){
				history = history.substr(1);
				history.push_back('1');
			}
			goto chalo;
		}else{
			if(m > 0){
				history = history.substr(1);
				history.push_back('0');
			}
		}





		cout<<"input 1 for print states of bgt for all iterations, else 0"<<endl;
		int print_states;
		cin>>print_states;

		if(want_history && print_states && m > 0){
			cout<<"all m-bit history and states of bgt just before branch instruction"<<endl;
			for(int i = 0; i < states.size(); i++){
				cout<<history_string[i]<<" "<<states[i]<<endl;
			}
		}else if(print_states){
			cout<<"all states of bgt"<<endl;
			for(int i = 0; i < states.size(); i++){
				cout<<states[i]<<endl;
			}
		}

		int mis_predict = 0;
		int to_print = 0;
		cout<<"input 1 to print <prediction real> for all iterations for bgt branch, else 0"<<endl;
		cin>>to_print;
		for(int i = 0; i < predict.size(); i++){
			if(to_print)cout<<predict[i]<<" "<<real[i]<<endl;
			if(predict[i] != real[i]){
				mis_predict += 1;
			}
		}
		cout<<mis_predict<<"/"<<predict.size()<<endl;


}
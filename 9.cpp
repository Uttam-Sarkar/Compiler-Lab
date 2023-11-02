#include <bits/stdc++.h>
using namespace std;
string ans="";
vector <string> inputV;
int ii=0;

int chomoskyNormalForm(string s){
	if(s == "PN" || s == "P" || s == "N" || s == "V" ){
		 ans = s;
	}
	else if(s == inputV[ii]){
		ii++;
		return 1;
	}
	return 0;
}	

int main()
{
	// Opening the file
	ifstream file;
	file.open("9.txt");
	string input;
	getline(cin, input);
	int len = input.size();
	string str = "";

	for(int i=0; i<len; i++){
		if(input[i]!=' '){
			str = str+input[i];
		}
		else{
			inputV.push_back(str);
			str = "";
		}
	}
	if(str.size()){
		inputV.push_back(str);
	}
	int countt = inputV.size();
	str = "";
	
	cout << "Output: ";

	int check=0;	
	vector<string> v;

	while (file >> str) {
		check = chomoskyNormalForm(str);
		if(check){
			v.push_back(ans);
			if(ii>=countt){
				break;
			}		
		}
	}

	int length = v.size();

	if(countt == 2 && length == 2 && ( (v[0]=="PN" || v[0]=="P") && (v[1]=="V") )){
		cout << "Valid" << endl;
	}
	else if(countt == 3 && length == 3 && (v[0]=="PN" || v[0]=="P") && (v[1]=="V" && v[2]=="N") ){
		cout << "Valid" << endl;
	}
	else{
		cout << "Invalid" << endl;
	}
}

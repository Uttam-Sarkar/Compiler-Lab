#include <bits/stdc++.h>
using namespace std;
string ans="";
string input;

int chomoskyNormalForm(string s){
	//cout << s << " " << input << endl;
	if(s == "PN" || s == "P" || s == "N" || s == "V" ){
		 ans = s;
	}
	else if(s == input){
		return 1;
	}
	return 0;
}	

int main()
{
	// Opening the file
	ifstream file;
	file.open("9.txt");

	cin >> input;

	string str;
	cout << "Output: ";

	int check=0;	
	vector<string> v;;

	while (file >> str) {
		check = chomoskyNormalForm(str);
		if(check){
			v.push_back(ans);
			break;
		}
	}

	int length = v.size();

	if(length==2 && ( (v[0]=="PN" || v[0]=="P") && (v[1]=="V") )){
		cout << "Valid" << endl;
	}
	else if( (v[0]=="PN" || v[0]=="P") && (v[1]=="V" && v[2]=="N") ){
		cout << "Valid" << endl;
	}
	else{
		cout << "Invalid" << endl;

	}
}

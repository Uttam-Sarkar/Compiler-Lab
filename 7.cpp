#include <bits/stdc++.h>
using namespace std;
string ans="";
string input;

int keywordOparatorConstantRecognizer(string s){
	if(s == "Keyword" || s == "Constant" || s == "Operator"){
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
	file.open("7.txt");

	cin >> input;

	string str;
	cout << "Output: ";

	int check=0;	
	while (file >> str) {
		check = keywordOparatorConstantRecognizer(str);
		if(check){
			cout << ans << endl;
			break;
		}
	}
	if(!check){
		cout << "identifier" << endl;
	}	

	return 0;
}

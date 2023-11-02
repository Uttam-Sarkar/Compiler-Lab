#include <bits/stdc++.h>
using namespace std;
bool variable(string s){
	int ans = 1;
	int length = s.size();
	
	if( !(s[2]=='_' && ((s[3]>='a' && s[3]<='z') || (s[3]>='A' && s[3]<='Z') || (s[3]>='0' && s[3]<='9')) )){
		return 0;
	}
	for(int i=3; i<length; i++){
		if( !((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))){
			ans = 0;
			break;
		}
	}
	return ans;
}
bool binaryNum(string s){
	int ans = 1;
	int length = s.size();
	
	if( !(s[1]=='0' || s[1]=='1')){
		return 0;
	}
	for(int i=1; i<length; i++){
	    if( !(s[i]=='0' || s[i]=='1')){
			ans = 0;
			break;
		}
	}
	return ans;

}


void lexicalAnalyzer(string s){
	int length = s.size();
	if(s[length-1]=='.'){
		s.pop_back();
		length = s.size();
	}
	cout << s << " =  ";
	if(length >= 4 && s[0]=='c' && s[1]=='h' && variable(s))
		cout << "Character variable" << endl;
	else if(length >= 4 && s[0]=='b' && s[1]=='n' && variable(s))
		cout << "Binary variable" << endl;
	else if(length>=2 && s[0]=='0' && binaryNum(s))
		cout << "Binary Number" << endl;
	else
		cout << "Undefined" << endl;
}	

int main()
{
	// Opening the file
	ifstream file;
	file.open("6.txt");

	string str;
	
	while (file >> str) {
		lexicalAnalyzer(str);
	}	

	return 0;
}

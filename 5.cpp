#include <bits/stdc++.h>
using namespace std;
bool floatVariable(string s){
	int ans = 1;
	int length = s.size();
	if((s[0]>='a' && s[0]<='h') || (s[0]>='A' && s[0]<='H') || (s[0]>='o' && s[0]<='z') || (s[0]>='O' && s[0]<='Z')){
		for(int i=1; i<length; i++){
			if( !((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))){
				ans = 0;
				break;
			}
		}					
	}
	else
		ans = 0;
	return ans;
}
bool floatNumber(string s){
	int ans = 1;
	int length = s.size();
	if(s[0]=='0' && s[1]=='.' && length <= 4){
		for(int i=2; i<length; i++){
			if(!(s[i]>='0' && s[i]<='9')){
				ans = 0;
				break;
			}
		}			
	}
	else if((s[0]>='1' && s[0]<='9')){
		int i = 0;
		for( ; i<length && s[i] != '.'; i++){
			if(!(s[0]>='0' && s[i]<='9')){
				ans=0;
				break;
			}
		}
		i++;
		if(i<length && i+3>length && ans){
			for( ;i<length; i++){
				if(!(s[0]>='0' && s[i]<='9')){
					ans=0;
					break;
				}
			}
		}
		else
		 ans = 0;

	}
	else
		ans = 0;
	return ans;
}
bool doubleNumber(string s){
	int ans = 1;
	int length = s.size();
	if(s[0]=='0' && s[1]=='.'){
		for(int i=2; i<length; i++){
			if(!(s[i]>='0' && s[i]<='9')){
				ans = 0;
				break;
			}
		}			
	}
	else if((s[0]>='1' && s[0]<='9')){
		int i = 0;
		for( ; i<length && s[i] != '.'; i++){
			if(!(s[0]>='0' && s[i]<='9')){
				ans=0;
				break;
			}
		}
		i++;
		if(i<length && ans){
			for( ;i<length; i++){
				if(!(s[0]>='0' && s[i]<='9')){
					ans=0;
					break;
				}
			}
		}
		else
		 ans = 0;
	}
	else
	 ans = 0;

	return ans;
}

void lexicalAnalyzer(string s){
	int length = s.size();
	if(s[length-1]=='.'){
		s.pop_back();
		length = s.size();
	}
	cout << s << " =  ";
	if(floatVariable(s))
		cout << "Float Variable" << endl;
	else if(floatNumber(s))
		cout << "Float Number" << endl;
	else if(doubleNumber(s))
		cout << "Double Number" << endl;
	else
		cout << "Undefined" << endl;
}	

int main()
{
	// Opening the file
	ifstream file;
	file.open("5.txt");

	string str;
	
	while (file >> str) {
		lexicalAnalyzer(str);
	}	

	return 0;
}

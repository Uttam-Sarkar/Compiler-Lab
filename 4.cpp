#include <bits/stdc++.h>
using namespace std;

void lexicalAnalyzer(string s){

	int length = s.size();
	if(s[length-1]=='.'){
		s.pop_back();
		length = s.size();
	}
	cout << s << ":  ";

	if((s[0]>='i' && s[0]<='n') || (s[0]>='I' && s[0]<='N'))
		cout << "Integer variable" << endl;
	else if(s[0]>='1' && s[0]<='9'){
		

		for (int i = 0; i < length; i++)
		{
			if(!(s[i]>='0' && s[i]<='9')){
				cout << "Undefind" << endl;
				return;
			}
		}

		if(length<=4)
			cout << "ShortInt Number" << endl;
		else
			cout << "LongInt Number" << endl;

	}
	else
		cout << "Undefind" << endl;


}	

int main()
{
	// Opening the file
	ifstream file;
	file.open("4.txt");

	string str;
	
	while (file >> str) {
		lexicalAnalyzer(str);
	}	

	return 0;
}

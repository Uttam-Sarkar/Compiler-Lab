#include <bits/stdc++.h>
using namespace std;
string ans="";
string input;

int chomoskyNormalForm(string s){
	//cout << s << " " << input << endl;
	if(s == "Keyword" || s == "Constant"){
		ans = s;
	}
	else if(s == "Arithmetic" || s == "Assignment" || s == "Relational" || s == "Logical" || s == "Bitwise" || s == "Other"){
		ans = s + " Oparator";
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
	file.open("8.txt");

	// taking input
	cin >> input;
	cout << "Output: ";

    string str;

	int check=0;	
	while (file >> str) {
		check = chomoskyNormalForm(str);
		if(check){
			cout << ans << endl;
			break;
		}
	}
	if(!check){
		int len = input.size();
		int identifier = 0;
		for(int i=0; i<len; i++){
			if((input[i] >= '0' && input[i] <= '9') || input[i]=='.'){
				if(input[i]=='.')
					identifier = 1;
			}
			else{
				identifier = 2;
				break;
			}
		}
		if(identifier == 0)
			cout << "Integer" << endl;
		else if(identifier == 1)
			cout << "Float" << endl;
		else
			cout << "identifier" << endl;
	}	

	return 0;
}

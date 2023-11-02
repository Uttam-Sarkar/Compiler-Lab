#include <bits/stdc++.h>
using namespace std;

void countFunction(vector<string> v){
	int words = 0;
	int letters = 0;
	int digits = 0;
	int others = 0;
	int length = v.size();

	for(int i=0; i<length; i++)
	{
		//cout  << v[i] << endl;
		int lenOfLine = v[i].size();

		for(int j=0; j<lenOfLine; j++){
			if(v[i][j]>='a' && v[i][j]<='z' || v[i][j]>='A' && v[i][j]<='Z')
				letters++;
			else if(v[i][j]>='0' && v[i][j]<='9')
				digits++;
			else if(v[i][j] == ' ')
				words++;
			else
				others++;
		}
		if(lenOfLine>0)
			words++;
		//cout << lenOfLine << " " << letters << " " << digits << " " << others << " " << words <<endl;
		cout << "Words : "<< words << endl; 
		cout << "Letters : "<< letters << endl; 
		cout << "Digits : "<< digits << endl; 
		cout << "Other Characters : "<< others << endl; 
	}
}

void separatesFunction(vector<string> v){
	vector<char> letterChar;
	vector<char> digitChar;
	vector<char> otherChar;

	int length = v.size();
	for(int i=0; i<length; i++)
	{
		int lenOfLine = v[i].size();

		for(int j=0; j<lenOfLine; j++){
			if(v[i][j]>='a' && v[i][j]<='z' || v[i][j]>='A' && v[i][j]<='Z')
				letterChar.push_back(v[i][j]);
			else if(v[i][j]>='0' && v[i][j]<='9')
				digitChar.push_back(v[i][j]);
			else if(v[i][j] == ' ')
				continue;
			else
				otherChar.push_back(v[i][j]);
		}
	}
	int l = letterChar.size();
	int d = digitChar.size();
	int o = otherChar.size();

	for (int i = 0; i < l ; ++i){
		cout << letterChar[i] ;
	}cout << endl;

	for (int i = 0; i < d ; ++i){
		cout << digitChar[i] ;
	}cout << endl;

	for (int i = 0; i < o ; ++i){
		cout << otherChar[i] ;
	}cout << endl;
}

int main()
{
	// Opening the file
	ifstream file;
	file.open("1.txt");

	vector<string> v;
	string str;

    cout << "The string is: " << endl;
	while (getline(file, str)) {
		v.push_back(str);
		cout << str << endl;
	}
 	
 	cout << endl;
 	cout << "The number of: " << endl;
	countFunction(v);
	cout << endl;
	cout << "Seperated Letters, Digits and Others: " << endl;
	separatesFunction(v);
	return 0;
}

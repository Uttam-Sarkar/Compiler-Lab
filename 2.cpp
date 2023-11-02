#include <bits/stdc++.h>
using namespace std;
	
void countVowelConsonant(vector<string> v){
	int vowel = 0;
	int consonant = 0;
	vector<char> vowelChar;
	vector<char> consonantChar;
	int length = v.size();


	for(int i=0; i<length; i++)
	{
		//cout  << v[i] << endl;
		int lenOfLine = v[i].size();

		for(int j=0; j<lenOfLine; j++){
			if(v[i][j]=='a' || v[i][j]=='e' || v[i][j]=='i' || v[i][j]=='o' || v[i][j]=='u' || v[i][j]=='A' || v[i][j]=='E' || v[i][j]=='I' || v[i][j]=='O' || v[i][j]=='U'){
				vowel++;
				vowelChar.push_back(v[i][j]);
			}
			else if((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z')){
				consonant++;
				consonantChar.push_back(v[i][j]);			
			}
		}
		cout << "The number of: " << endl;
		cout << "Vowel(s) : "<< vowel << endl; 
		cout << "Consonant(s) : "<< consonant << endl;
		cout << endl;

		int v = vowelChar.size();
		int c = consonantChar.size();
		cout << "The existing Vowel(s): ";
		for(int i=0; i<v; i++){
			cout << vowelChar[i];
		}cout << endl;
		cout << "The existing Consonant(s): ";
		for(int i=0; i<c; i++){
			cout << consonantChar[i];
		}cout << endl;

	}
}

void separatesFunction(){
	ifstream file;
	file.open("2.txt");

	vector<string> s_w_v;
	vector<string> s_w_c;

	string str2;
	while ((file >> str2)) {
		if(str2[0]=='a' || str2[0]=='e' || str2[0]=='i' || str2[0]=='o' || str2[0]=='u' || str2[0]=='A' || str2[0]=='E' || str2[0]=='I' || str2[0]=='O' || str2[0]=='U'){
				s_w_v.push_back(str2);
			}
			else if((str2[0]>='a' && str2[0]<='z') || (str2[0]>='A' && str2[0]<='Z')){
				s_w_c.push_back(str2);			
			}
	}
	int v = s_w_v.size();
	int c = s_w_c.size();
	cout << "Starting with Vowel: ";
	for(int i=0; i<v; i++){
		cout << s_w_v[i] ;
		if(i<v-1)
			cout << ", ";
	}cout << endl;
	cout << "Starting with Consonant: ";
	for(int i=0; i<c; i++){
		cout << s_w_c[i] ;
		if(i<v-1)
			cout << ", ";
	}cout << endl;
}

int main()
{
	// Opening the file
	ifstream file;
	file.open("2.txt");

	vector<string> v;
	string str;
	
    cout << "The string is: " << endl;
	while (getline(file, str)) {
		v.push_back(str);
		cout << str << endl;
	}
 	
 	cout << endl;
	countVowelConsonant(v);
	cout << endl;
	separatesFunction();


	return 0;
}

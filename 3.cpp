#include <bits/stdc++.h>
using namespace std;

void department(string dept){
	if(dept == "CSE")
		cout << "Computer Science & Engineering";
	else if(dept == "ICE")
		cout << "Information Communication & Engineering";
	else if(dept == "IR")
		cout << "International Relationship";
	else
		cout << "Error";
}
void year(char c){
	if(c =='1')
		cout << "1st year";
	else if(c =='2')
		cout << "2nd year";
	else if(c =='3')
		cout << "3rd year";
	else if(c =='4')
		cout << "4th year";
	else
		cout << "Error";
}
void semister(char c){
	if(c == '1')
		cout << "1st semister";
	else if(c == '2')
		cout << "2nd semister";
	else if(c == '3')
		cout << "3rd semister";
	else if(c == '4')
		cout << "4th semister";
	else
		cout << "Error";	
}
void course(string s){
	if(s == "CSE-314")
		cout << "Compiler Design";
	else if(s == "CSE-121")
		cout << "Technical and Communicative English";
	else if(s == "ICE-314")
		cout << "Compiler Design";
	else if(s == "ICE-121")
		cout << "Technical and Communicative English";
	else if(s == "IR-314")
		cout << "Foreign Cilture";
	else if(s == "IR-121")
		cout << "Technical and Communicative English";	
}
void type(char c){
	if(c == '1')
		cout << "Theory";
	else if(c == '2')
		cout << "Lab";
	else
		cout << "Error";
}

void abbreviator(string s){
	cout << s << " =  ";
	int length = s.size();

	int i = 0;
	string dept="";
	while(s[i] != '-'){
		dept = dept + s[i];
		i++;
	}	

	department(dept);
	cout << ", ";
	dept = dept + s[i];//for '_'
	
	i++;
	dept = dept + s[i];
	year(s[i]);
	cout << ", ";

	i++;
	dept = dept + s[i];
	semister(s[i]);
	cout << ", ";

	i++;
	dept = dept + s[i];
	course(dept);
	cout << ", ";

	i++;
	type(s[i]);
	cout << "." << endl;
}

int main(){
	// Opening the file
	ifstream file;
	file.open("3.txt");

	string s;

	// cin >> s;
	// abbreviator(s);
	
	while (file >> s) {
		abbreviator(s);
	}	

	return 0;
	

}
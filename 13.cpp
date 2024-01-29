// epcilon will not work here..epcilon will work as a terminator
#include <bits/stdc++.h>
using namespace std;
vector<pair<string, string>> grammer;
map<string, set<char>> First;



void findFirst(){
	for (int i = 0; i < grammer.size(); ++i){
		string leftPart = grammer[i].first;
		for(int j=0; j<grammer.size(); j++){
			if(grammer[j].first == leftPart){
				string rightPart = grammer[j].second;
				First[leftPart].insert(rightPart[0]);
			}
		}
	}
	for(int i=0; i<grammer.size(); i++){
		if(i!=0 && First[grammer[i].first] == First[grammer[i-1].first]){
			continue;
		}
	
		vector<char> v;
		for (auto& str : First[grammer[i].first]) {
	 		//cout << str << " ";
	 		if(str>='A' && str<='Z'){
	 			v.push_back(str);
 			}
		}
	
		if(!v.empty()){
			for(int j=0; j<v.size(); j++){
				string variable ;
				variable = v[j];
				First[grammer[i].first].insert(First[variable].begin(),First[variable].end());
				First[grammer[i].first].erase(variable[0]);
			}
		}
		v.clear();
	}
	//cout << endl << endl;
	
	for(int i=0; i<grammer.size(); i++){
		if(i!=0 && First[grammer[i].first] == First[grammer[i-1].first]){
			continue;
		}
		cout << "First[" << grammer[i].first << "] => "; 
		for (auto& str : First[grammer[i].first]) {
	 		cout << str << " ";
		}
		 cout << endl;
	}

}

int main()
{
	// assign grammer from txt file
	//vector<pair<string, string>> grammer;
	// Opening the file
	ifstream file;
	file.open("13Grammer.txt");

	string str;
	bool check = false;
	string leftSide =  "";
	// grammer map taken as global variable 
// assign left and right side of grammer into map
	while (file >> str) {
		if(check){
			check = false;
			grammer.push_back({leftSide, str});
		}
		else if(str == "="){
			check = true;
		}
		else{
			leftSide = str;
		}
	}
	cout << "Grammer:" << endl;
	for (int i = 0; i < grammer.size(); ++i){
		cout << grammer[i].first << " -> " << grammer[i].second << endl;
	}
// end of asign grammer
cout << endl;
findFirst();

}
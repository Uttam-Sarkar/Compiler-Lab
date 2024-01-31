#include <bits/stdc++.h>
using namespace std;
vector<pair<string, string>> grammer;
map<string, set<char>> First;
map<char, set<char>> Follow;

void findFirst(){
	for (int i = grammer.size()-1; i >= 0; i--){
		string leftPart = grammer[i].first;
		for(int j=0; j<grammer.size(); j++){
			if(grammer[j].first == leftPart){
				string rightPart = grammer[j].second;
				if(!(rightPart[0] >= 'A' && rightPart[0] <= 'Z') || rightPart[0] == '~'){
					First[leftPart].insert(rightPart[0]);
				}else{
					int vPos = 0;
					uttam:
					string rightPartS = rightPart.substr(vPos, vPos + 1);// = rightPart[0];
					for (auto& ch : First[rightPartS]) {
						if(ch == '~'){
							vPos++;
							goto uttam;
						}
	 					First[leftPart].insert(ch);
					}
				}				
			}
		}
	}
}
void printFirst(){
	for(int i=0; i<grammer.size(); i++){
		if(i!=0 && grammer[i].first == grammer[i-1].first){
			continue;
		}
		cout << "First[" << grammer[i].first << "] => "; 
		for (auto& str : First[grammer[i].first]) {
	 		cout << str << " ";
		}
		 cout << endl;
	}
}

void findFollow(){
	Follow[grammer[0].first[0]].insert('$');
	for(int i=0; i<grammer.size(); i++){	
	cout << "i"<< i <<" ";	
		if(i!=0 && grammer[i].first == grammer[i-1].first){
			continue;
		}

		char followValue = grammer[i].first[0];
		for(int j=0; j<grammer.size(); j++){
			cout << "j"<< j <<" ";
			string rightPart =  grammer[j].second;
			char leftPart = grammer[j].first[0];

			for (int k = 0; k < rightPart.size(); k++)
			{
				cout << "k"<< k <<" ";
				if(rightPart[k] == followValue){
					if(k == rightPart.size()-1 ){
						// left side's Follow will kept
						for (auto& ch : Follow[leftPart]) {
							// string s;
							// s[0] = followValue; 
	 						Follow[followValue].insert(ch);
						}
					}else if(rightPart[k+1] >= 'A' && rightPart[k+1] <= 'Z'){
						string p ="" + rightPart[k+1];
						for (auto& ch : First[p]) {
							if(ch == '~'){
								//epcilon will not exist in Follow
								continue;
							}
	 						Follow[followValue].insert(ch);
						}
					}
					else{
						Follow[followValue].insert(rightPart[k+1]);
					}
				}
				cout<< endl;
			}cout << endl;
		}
		cout << endl;
	}

}
void printFollow(){
	for(int i=0; i<grammer.size(); i++){
		if(i!=0 && grammer[i].first == grammer[i-1].first){
			continue;
		}
		cout << "Follow[" << grammer[i].first << "] => "; 
		for (auto& str : Follow[grammer[i].first[0]]) {
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
printFirst();
cout << endl;
findFollow();
printFollow();
}


// void findFirst(){
// 	for (int i = grammer.size()-1; i >= 0; i--){
// 		string leftPart = grammer[i].first;
// 		for(int j=0; j<grammer.size(); j++){
// 			if(grammer[j].first == leftPart){
// 				string rightPart = grammer[j].second;
// 				if(!(rightPart[0] >= 'A' && rightPart[0] <= 'Z') || rightPart[0] == '~'){
// 					First[leftPart].insert(rightPart[0]);
// 				}else{
// 					int vPos = 0;
// 					uttam:
// 					string rightPartS = rightPart.substr(vPos, vPos + 1);// = rightPart[0];
// 					for (auto& ch : First[rightPartS]) {
// 						if(ch == '~'){
// 							vPos++;
// 							goto uttam;
// 						}
// 	 					First[leftPart].insert(ch);
// 					}
// 				}				
// 			}
// 		}
// 	}
// }
// void printFirst(){
// 	for(int i=0; i<grammer.size(); i++){
// 		if(i!=0 && grammer[i].first == grammer[i-1].first){
// 			continue;
// 		}
// 		cout << "First[" << grammer[i].first << "] => "; 
// 		for (auto& str : First[grammer[i].first]) {
// 	 		cout << str << " ";
// 		}
// 		 cout << endl;
// 	}
// }
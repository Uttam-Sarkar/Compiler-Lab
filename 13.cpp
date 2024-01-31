#include <bits/stdc++.h>
using namespace std;
vector<pair<char, string>> grammer;
map<char, set<char>> First;
map<char, set<char>> Follow;

void findFirst(){
	for (int i = grammer.size()-1; i >= 0; i--){
		char leftPart = grammer[i].first;
		for(int j=0; j<grammer.size(); j++){
			if(grammer[j].first == leftPart){
				string rightPart = grammer[j].second;
				if(!(rightPart[0] >= 'A' && rightPart[0] <= 'Z') || rightPart[0] == '~'){
					First[leftPart].insert(rightPart[0]);
				}else{
					int vPos = 0;
					uttam:
					for (auto& ch : First[rightPart[vPos]]) {
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
	Follow[grammer[0].first].insert('$');
	for(int i=0; i<grammer.size(); i++){		
		if(i!=0 && grammer[i].first == grammer[i-1].first){
			continue;
		}

		char followValue = grammer[i].first;
		for(int j=0; j<grammer.size(); j++){
			char leftPart = grammer[j].first;
			string rightPart =  grammer[j].second;

			for (int k = 0; k < rightPart.size(); k++)
			{
				if(rightPart[k] == followValue){
					
					int vPos = k;
					uttam2:

					if(vPos == rightPart.size()-1 ){
						// left side's Follow will kept
						for (auto& ch : Follow[leftPart]) {
	 						Follow[followValue].insert(ch);
						}
					}else if(rightPart[vPos+1] >= 'A' && rightPart[vPos+1] <= 'Z'){
						for (auto& ch : First[rightPart[vPos+1]]) {
							if(ch == '~'){
								vPos++;
								goto uttam2;
							}
	 						Follow[followValue].insert(ch);
						}
					}
					else{
						Follow[followValue].insert(rightPart[vPos+1]);
					}
				}
				
			}
		}
	}

}
void printFollow(){
	for(int i=0; i<grammer.size(); i++){
		if(i!=0 && grammer[i].first == grammer[i-1].first){
			continue;
		}
		cout << "Follow[" << grammer[i].first << "] => "; 
		for (auto& str : Follow[grammer[i].first]) {
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
	char leftSide =  'a';
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

			leftSide = str[0];
		}
	}
	cout << "Grammer:" << endl;
	for (int i = 0; i < grammer.size(); ++i){
		// print Left side
		if(i==0 || grammer[i].first != grammer[i-1].first){
			cout << grammer[i].first << " -> ";
		}

		//Print Right side
		if(i != (grammer.size()-1) && grammer[i].first == grammer[i+1].first){
			cout << grammer[i].second << " | " ;
			continue;
		}
		cout<< grammer[i].second << endl;
	}
// end of asign grammer
cout << endl;
findFirst();
printFirst();
cout << endl;
// give find follow two time otherwise sometimes it can't give right ans
//findFollow();
findFollow();
printFollow();
}
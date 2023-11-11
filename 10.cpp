#include <bits/stdc++.h>
using namespace std;

int main()
{
	// assign grammer from txt file
	vector<pair<string, string>> grammer;

	// Opening the file
	ifstream file;
	file.open("10Grammer.txt");

	string str;
	bool check = false;
	string leftSide =  "";
	
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
	for (int i = 0; i < grammer.size(); ++i)
	{
		/* code */
		cout << grammer[i].first << " -> " << grammer[i].second << endl;
	}
// end of asign grammer

	//word
	// take word from input
	string word;
	//cin >> word;
	word = "id + id * id";
	cout << "Word : " << word << endl;

	string stack = "$";
	string inputBuffer = word + " $";

	string shift = "";

	cout << "-------- Stack ----- Input Buffer" << endl;
	cout << "        : " << stack << " ----- " << inputBuffer << endl; 

	while(inputBuffer!="$"){

		while( inputBuffer[0] != '$' && inputBuffer[0] != ' ')
		{
			stack = stack + inputBuffer[0];
			inputBuffer.erase(0,1);
		}
		if(inputBuffer[0] == ' ') inputBuffer.erase(0,1);
		
		cout <<"Shift   : " << stack << " ----- ";
		cout << inputBuffer << endl;


		// reduced
		for (int i = 0; i < grammer.size(); ++i){
			int pos = stack.find(grammer[i].second);
			if(pos>=0){
				int siz = grammer[i].second.size();
				stack = stack.erase(pos,siz);
				stack = stack + grammer[i].first;
				cout <<"Reduced : " << stack << " ----- ";
				cout << inputBuffer  << endl;

				i=-1;
			}
			//cout << pos << endl;
		}


	}


	cout << endl;
	if(("$" + grammer[0].first )== stack){
		cout << "Output : Valid" << endl;
	}
	else{
		cout << "Output : Invalid" << endl;
	}
}
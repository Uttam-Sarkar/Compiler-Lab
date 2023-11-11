#include <bits/stdc++.h>
using namespace std;

int main()
{
	string ans = "";

	string input;
	// Opening the file
	ifstream file;
	file.open("12.txt");
	getline(file, input);

	// length of input
	int n = input.size();

	for(int i=0; i<n; i++){
		//cout << input[i] << " " << n << endl;
		if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i]== '/'){
			ans = ans + "0";
		}
		else{
			ans = ans + "1";
			while(i<input.size() && !(input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/')){
				i++;
			}
		}
	}

	bool validity = true;
	for(int i=0; i<n; i++){
		if( (i%2 == 0 && ans[i] == '0') || (i%2 == 1 && ans[i] == '1'))
		{
			validity = false;
			break;
		}
	}
	if(validity)
		cout << "Output: VALID" << endl;
	else
		cout << "Output: INVALID" << endl;
}
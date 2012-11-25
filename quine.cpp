#include <iostream>
#include <string>
using namespace std;

string escape (const string str) {
	string result = string(1, str[0]);
	
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == (char)10) {
			result += (char)92;
			result += (char)110;
		} else if (str[i] == (char)9) {
			result += (char)92;
			result += (char)116;
		} else
			result += str[i];
	}
	
	return result;
}

int main() {
	string quine = "#include <iostream>\n#include <string>\nusing namespace std;\n\nstring escape (const string str) {\n\tstring result = string(1, str[0]);\n\t\n\tfor (int i = 1; i < str.length(); i++) {\n\t\tif (str[i] == (char)10) {\n\t\t\tresult += (char)92;\n\t\t\tresult += (char)110;\n\t\t} else if (str[i] == (char)9) {\n\t\t\tresult += (char)92;\n\t\t\tresult += (char)116;\n\t\t} else\n\t\t\tresult += str[i];\n\t}\n\t\n\treturn result;\n}\n\nint main() {\n\tstring quine = ;\n\t\n\tchar quote = (char)34;\n\tquine = quine.substr(0, 414) + quote + escape(quine) + quote + quine.substr(414);\n\t\n\tcout << quine;\n\treturn 0;\n}";
	
	char quote = (char)34;
	quine = quine.substr(0, 414) + quote + escape(quine) + quote + quine.substr(414);
	
	cout << quine;
	return 0;
}
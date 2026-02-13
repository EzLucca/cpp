#include <iostream>
#include <string>
#include <fstream>

int main (int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "./program <filename> <string1> <string2>\n";
		return (1);
	}
	else {
		std::string filename = argv[1];
		std::string string1 = argv[2];
		std::string string2 = argv[3];

		if(string1.empty()) {
			std::cerr << "Error: string1 should not be empty.\n";
			return (1);
		}

		std::ifstream infile(filename);
		if(infile.fail()) {
			std::cerr << "Error: Could not open the file.\n";
			return (1);
		}

		std::ofstream outfile(filename + ".replace");
		if(outfile.fail()) {
			std::cerr << "Error: Creating the out file.\n";
			infile.close();
			return (1);
		}

		std::string line;
		while(std::getline(infile, line, '\0')) {
			size_t pos = 0;
			std::string result;
			std::size_t found;

			while ((found = line.find(string1, pos)) != std::string::npos)
			{
				result += line.substr(pos, found - pos) + string2;
				pos = found + string1.length();
			}
			result += line.substr(pos);
			outfile << result;
		}
		infile.close();
		outfile.close();
		return (0);
	}
}

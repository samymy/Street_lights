#include <iostream>
#include <fstream>

#include "Range.hpp"
#include "Parser.hpp"

using namespace std;

int		main(int argc, char** argv) {

	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <file>" << endl;
		return 0;
	}

	Parser				parser;
	ifstream			in(argv[1]);
	unsigned long long 	result;

	try {
		parser.parse(in);
		in.close();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
		return 1;
	}

	result = parser.getRows();
	result *= parser.getColumns();

	for (auto pair : parser.getRanges()) {

		Range::unionRanges(pair.second);
		for (auto union_range : pair.second)
			result -= union_range.getLength();
	}

	cout << result;
}

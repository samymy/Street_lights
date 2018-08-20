#include <string>
#include <cmath>
#include <regex>

using std::string;
using std::regex;
using std::invalid_argument;

#include "Parser.hpp"

Parser::map_of_vectors&	Parser::getRanges() {

	return ranges;
}

unsigned int			Parser::getRows() const {

	return rows;
}

unsigned int			Parser::getColumns() const {

	return columns;
}

unsigned int			Parser::getPaths() const {

	return paths;
}

void					Parser::parseSizes(string sizes) {

	rows = stoul(sizes);
	if (rows < 1 || rows > pow(10, 9))
		throw invalid_argument("The number of rows is too large or equal to zero");

	sizes = sizes.substr(sizes.find(' ') + 1);
	columns = stoul(sizes);
	if (columns < 1 || columns > pow(10, 9))
		throw invalid_argument("The number of columns is too large or equal to zero");

	sizes = sizes.substr(sizes.find(' ') + 1);
	paths = stoul(sizes);
	if (paths > 1000)
		throw invalid_argument("The number of paths is too large");
}

void					Parser::parsePath(string path) {

	unsigned int row, col_from, col_to;

	row = stoul(path);
	if (row < 1 || row > rows)
		throw invalid_argument("The row number is too large or equal to zero");

	path = path.substr(path.find(' ') + 1);
	col_from = stoul(path);
	if (col_from < 1 || col_from > columns)
		throw invalid_argument("The column number is too large or equal to zero");

	path = path.substr(path.find(' ') + 1);
	col_to = stoul(path);
	if (col_to < 1 || col_to > columns)
		throw invalid_argument("The column number is too large or equal to zero");

	if (col_to < col_from)
		throw invalid_argument("The initial point of the path is more than its final point");

	map_of_vectors::mapped_type&	ref_vector = ranges[row];

	ref_vector.push_back(Range(col_from, col_to));
}

void					Parser::parse(istream& in) {

	regex			pattern("\\d{1,10} \\d{1,10} \\d{1,10}");
	string			sizes, path;
	unsigned short	path_idx;

	if (!in)
		throw invalid_argument("The file does not exist");

	getline(in, sizes);
	if (regex_match(sizes, pattern)) {
		try {
			parseSizes(sizes);
		}
		catch (...) {
			throw;
		}
	}
	else
		throw invalid_argument("Incorrect number");

	path_idx = 0;
	while (getline(in, path)) {

		++path_idx;
		if (regex_match(path, pattern)) {
			try {
				parsePath(path);
			}
			catch (...) {
				throw;
			}
		}
		else
			throw invalid_argument("Incorrect number");
	}

	if (path_idx != paths)
		throw invalid_argument("The number of paths does not correspond to the actual number");	
}

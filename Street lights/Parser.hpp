#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using std::istream;
using std::unordered_map;
using std::vector;
using std::string;

#include "Range.hpp"

class Parser {

public:

	typedef unordered_map<unsigned int, vector<Range>>	map_of_vectors;

	void			parse(istream&);

	map_of_vectors&	getRanges();
	unsigned int	getRows() const;
	unsigned int	getColumns() const;
	unsigned int	getPaths() const;

private:
	map_of_vectors	ranges;
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	paths;

	void			parseSizes(string);
	void			parsePath(string);
	
};

#endif

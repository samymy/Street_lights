#ifndef RANGE_HPP
#define RANGE_HPP

#include <vector>
using std::vector;

class Range {
	unsigned int	begin;
	unsigned int	end;

public:
	Range(unsigned int, unsigned int);

	unsigned int	getBegin() const;
	unsigned int	getEnd() const;

	bool			isIntersected(const Range&) const;
	unsigned int	getLength() const;

	Range			operator+(const Range&) const;

	static void		unionRanges(vector<Range>&);
};

#endif

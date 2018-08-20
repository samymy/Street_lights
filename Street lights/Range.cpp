#include <algorithm>
using std::min;
using std::max;
using std::sort;

#include "Range.hpp"

Range::Range(unsigned int _begin, unsigned int _end): begin(_begin), end(_end) {}

unsigned int	Range::getBegin() const {

	return begin;
}

unsigned int	Range::getEnd() const {

	return end;
}

bool			Range::isIntersected(const Range& range) const {

	return (end >= range.getBegin() && end <= range.getEnd()) ||
			(begin >= range.getBegin() && begin <= range.getEnd()) ||
			(begin < range.getBegin() && end > range.getEnd());
}

unsigned int	Range::getLength() const {

	return end - begin + 1;
}

Range			Range::operator+(const Range& range) const {

	return Range(min(begin, range.getBegin()), max(end, range.getEnd()));
}

void			Range::unionRanges(vector<Range>& ranges) {

	if (ranges.empty())
		return;

	sort(ranges.begin(), ranges.end(),
		[](const Range& a, const Range& b){
			return a.getBegin() < b.getBegin();
		}
	);

	vector<Range>	union_ranges;
	Range			union_range(*ranges.begin());

	for (auto range : ranges)
		if (union_range.isIntersected(range))
			union_range = union_range + range;
		else {
			union_ranges.push_back(union_range);
			union_range = range;
		}
	union_ranges.push_back(union_range);

	ranges = union_ranges;
}

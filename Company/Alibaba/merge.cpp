#include <iostream>
#include <list>
#include <string>

using namespace std;
struct TimeSegment{
	uint64_t btime;
	uint64_t etime;
	TimeSegment() : btime(0), etime(0){
	}
	TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_){
	}
	bool operator()(const TimeSegment t1,const TimeSegment t2){  
        return t1.btime < t2.btime;  
    }  
};


inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment>& lstTimeSegment){
	// TODO
	TimeSegment second;
	second.btime = nBeginTime;
	second.etime = nEndTime;
	cout << lstTimeSegment.size() << endl;

	lstTimeSegment.push_back(second);
	cout << lstTimeSegment.size() << endl;
	lstTimeSegment.sort(TimeSegment());
	list<TimeSegment> res;
	res.push_back(lstTimeSegment.front());
	auto it = lstTimeSegment.begin();
	it++;
	for(;it != lstTimeSegment.end();it++){
		if(res.back().etime < it->btime)
			res.push_back(*it);
		else
			res.back().etime = max(res.back().etime, it->etime);
	}
	cout << res.size() << endl;
	lstTimeSegment = res;
}

TimeSegment ParseTimeSegmentString(const std::string& input){
	TimeSegment timestamp;
	size_t nPos = input.find("-");
	size_t nLength = input.length();
	if (nPos > 0 && nPos < nLength){
		try{
			timestamp.btime = std::stoull(input.substr(0, nPos));
			timestamp.etime = std::stoull(input.substr(nPos + 1, nLength));
		}
		catch (...){
			std::cout << "请输入有效数据.\n";
		}
	}
	else{
		std::cout << "请输入有效数据.\n";
	}

	return timestamp;
}

std::list<TimeSegment> ParseTimeSegmentList(const std::string& input){
	TimeSegment timestamp;
	std::list<TimeSegment> lstTimestamp;
	std::string temp;
	size_t nStartPos = 0;
	size_t nEndPos = input.find(",");
	size_t nLength = input.length();
	while (nEndPos > nStartPos && nEndPos <= nLength){
		temp = input.substr(nStartPos, nEndPos);
		if (temp.size() > 0){
			timestamp = ParseTimeSegmentString(temp);
			lstTimestamp.push_back(timestamp);
		}
		nStartPos = nEndPos + 1;
		nEndPos = input.find(",", nStartPos);
		if (-1 == nEndPos){
			nEndPos = nLength;
		}
	}

	return lstTimestamp;
}

int main(int argc, char *argv[]) {
	std::string input;
        std::cin >> input;
	int nPos = input.find(";");
	std::list<TimeSegment> lstTimestamp = ParseTimeSegmentList(input.substr(0, nPos));
	TimeSegment timestamp = ParseTimeSegmentString(input.substr(nPos + 1, input.size()));

	MergeTimeSegment(timestamp.btime, timestamp.etime, lstTimestamp);

	for (auto it = lstTimestamp.begin(); it != lstTimestamp.end();) {
		std::cout << it->btime << "-" << it->etime;
		if (++it != lstTimestamp.end()){
			std::cout << ",";
		}
	}

	return 0;
}
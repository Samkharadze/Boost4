#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <vector>
#include "boost/filesystem.hpp"

namespace fs = boost::filesystem;

class dirparser
{
public:
	explicit dirparser(std::string path);
	void parse();
	void print_info();
	std::map<std::string, std::map<std::string, std::vector<std::string>>> get_brockers()
	{
		return m_brockers;
	}
private:
	void check_path(fs::path value);
	std::pair<std::string, std::string> brockers_parse(std::string &fn);
	void add_brocker(std::string &brocker, std::string &account, std::string date);
	std::string get_brocker_name(fs::path &dir);
private:
	fs::path m_path;
	std::map<std::string, std::map<std::string, std::vector<std::string>>> m_brockers;
};
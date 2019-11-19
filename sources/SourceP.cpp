#include <boost/regex.hpp>
#include <algorithm>
#include "HeaderP.h"

using namespace boost::filesystem;

dirparser::dirparser(std::string path): m_path(path)
{

}

void dirparser::parse()
{
    if (!fs::exists(m_path))
	{
    throw std::runtime_error("path is not exists");
    }
    for (const fs::directory_entry& x : fs::directory_iterator{m_path})
    {
        check_path(x.path());
    }
}


void dirparser::print_info()
{
    std::cout << std::endl << "============Info =========" << std::endl;
    for (auto& brocker : m_brockers)
    {
        for (auto& account : brocker.second)
        {
            std::sort(account.second.rbegin(), account.second.rend());

            std::cout << "brocker: " << brocker.first
                      << "\t account: " << account.first
                      << "\t files: " << account.second.size()
                      << "\t lastdate: " << account.second[0]
                      << std::endl;
        }
    }
}

void dirparser::check_path(fs::path value)
{
    if (is_regular_file(value))
    {
        const boost::regex file_filter("balance_[0-9]{8}_[0-9]{8}.txt");

        if (boost::regex_match(value.filename().string(), file_filter, boost::regex_constants::match_default))
        {
            fs::path dir = value.parent_path();
            std::string brocker = get_brocker_name(dir);
            std::string filename = value.filename().string();
            std::cout << brocker << " " << filename << std::endl;
            std::pair<std::string, std::string> item_pair = brockers_parse(filename);
            add_brocker(brocker, item_pair.first, item_pair.second);
        }
    }
    else if (is_directory(value))
    {
        for (const fs::directory_entry& x : fs::directory_iterator{value})
        {
            check_path(x.path());
        }
    }
    else if (is_symlink(value))
    {
        fs::path dir;
        fs::read_symlink(dir);
        if(!dir.empty())
        {
            check_path(dir);
        }
    }
    else
    {
      throw std::runtime_error("incorrect object");
    }
}

std::pair<std::string, std::string> dirparser::brockers_parse(std::string &fn)
{
    std::string raw = fs::change_extension(fn, "").string();
    raw.erase(0, 8);
    std::string account(raw.substr(0, 8));
    std::string date(raw.substr(9, 8));
    return std::make_pair(account, date);
}

void dirparser::add_brocker(std::string &brocker, std::string &account, std::string date)
{
    std::vector<std::string> temp_vector;
    std::map<std::string, std::vector<std::string>> temp_map;
    std::map<std::string, std::map<std::string, std::vector<std::string>>>::iterator it_brocker = m_brockers.find(brocker);
    if(it_brocker != m_brockers.end())
    temp_map = m_brockers[brocker];
    std::map<std::string, std::vector<std::string>>::iterator it_account = temp_map.find(account);
    if(it_account != temp_map.end())
    temp_vector = temp_map[account];
    temp_vector.push_back(date);
    temp_map[account] = temp_vector;
    m_brockers[brocker] = temp_map;
}

std::string dirparser::get_brocker_name(boost::filesystem::path &dir)
{
    std::size_t sep = dir.string().find_last_of("\\/");
    if (sep != std::string::npos)
        return (dir.string().substr(sep + 1, dir.string().size() - sep - 1));

    return std::string();
}
int main(int argc, char **argv)
{
	std::string path_to_ftp;
	if (argc < 2) 
	{
		path_to_ftp = std::string(argv[1]);
	}
	else
	{
		path_to_ftp = "../";
	}
}
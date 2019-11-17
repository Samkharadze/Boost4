

#include <gtest/gtest.h>
#include <HeaderP.h>

TEST(test, simple) {
	std::string path_to_ftp = "../";
	dirparser parser(path_to_ftp);
	parser.parse();
	parser.print_info();
	EXPECT_EQ(parser.get_brockers().size(), 3);
}
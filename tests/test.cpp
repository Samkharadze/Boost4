// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <HeaderP.h>
#include "SourceP.cpp"

TEST(Boost4, test1)
 {
		std::string path_to_ftp = "../";
        dirparser(path_to_ftp, path_to_ftp.length() + 1);
        add_brocker();
		EXPECT_EQ(broker.size(), 3);
}

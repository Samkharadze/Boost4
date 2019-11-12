// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <HeaderP.h>

TEST(Boost4, test1)
 {
		string path_to_ftp = "../";
		fileFind(path_to_ftp, path_to_ftp.length() + 1);
		FileGet();
		EXPECT_EQ(brokers.size(), 3);
}

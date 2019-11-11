// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <HeaderP.h>

TEST(Boost4, test1)
{
    std::string ftp_path = "../misc/ftp/";
    fillup(ftp_path);
    EXPECT_EQ(brokers.size(), 3);  
}
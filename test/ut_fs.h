#ifndef UT_FILE_H
#define UT_FILE_H

#include <gtest/gtest.h>
#include <string>
#include "../src/file.h"
#include "../src/folder.h"
#include "../src/link.h"
#include "../src/filesystem_builder.h"

TEST(FileSystemTest, NodeTypeError)
{
    ASSERT_ANY_THROW(new File("./123"));               //If the node doesn't exist, you should throw string "Node is not exist!"
    ASSERT_ANY_THROW(new File("./test_data/folder"));  //If the File doesn't exist, you should throw string "It is not File!"
    ASSERT_ANY_THROW(new Folder("./test_data/hello")); //If the Folder doesn't exist, you should throw string "It is not Folder!"
    ASSERT_ANY_THROW(new Link("./test_data/test"));    //If the Link doesn't exist, you should throw string "It is not Link!"
}

TEST(FileSystemBuilder, folder)
{
    FileSystemBuilder *fb = FileSystemBuilder::instance();
    fb->build("test/test_folder");
    ASSERT_EQ("test_folder", fb->getRoot()->name());
    ASSERT_EQ("test/test_folder", fb->getRoot()->getPath());
}

TEST(FileSystemBuilder, file)
{
    FileSystemBuilder *fb = FileSystemBuilder::instance();
    fb->build("test/test_folder/hw/a.out");
    ASSERT_EQ("a.out", fb->getRoot()->name());
    ASSERT_EQ("test/test_folder/hw/a.out", fb->getRoot()->getPath());
}

#endif

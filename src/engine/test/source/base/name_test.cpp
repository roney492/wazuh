#include <name.hpp>

#include <fmt/format.h>
#include <gtest/gtest.h>

#include <numeric>

TEST(NameTest, InitializationDefault)
{
    base::Name name;
    ASSERT_TRUE(name.parts().empty());
}

TEST(NameTest, InitializationParts)
{
    base::Name name ({"type", "name", "version"});
    ASSERT_EQ(name.parts().size(), 3);
    ASSERT_EQ(name.parts()[0], "type");
    ASSERT_EQ(name.parts()[1], "name");
    ASSERT_EQ(name.parts()[2], "version");
}

TEST(NameTest, InitializationPartsMax)
{
    ASSERT_THROW(base::Name({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"}),
                 std::runtime_error);
}

TEST(NameTest, InitializationFullNameString)
{
    std::string fullName = fmt::format(
        "type{}name{}version", base::Name::SEPARATOR_S, base::Name::SEPARATOR_S);
    base::Name name(fullName);
    ASSERT_EQ(name.parts().size(), 3);
    ASSERT_EQ(name.parts()[0], "type");
    ASSERT_EQ(name.parts()[1], "name");
    ASSERT_EQ(name.parts()[2], "version");
}

TEST(NameTest, InitializationFullNameStringMaxParts)
{
    std::vector<std::string> parts;
    for (int i = 0; i < base::Name::MAX_PARTS + 1; i++)
    {
        parts.push_back(fmt::format("part{}", i));
    }

    std::string nameStr = std::accumulate(parts.begin(),
                                          parts.end(),
                                          std::string(),
                                          [](std::string& a, const std::string& b)
                                          { return a + base::Name::SEPARATOR_S + b; });

    ASSERT_THROW(base::Name name(nameStr), std::runtime_error);
}

TEST(NameTest, InitializationFullNameChar)
{
    std::string fullName = fmt::format(
        "type{}name{}version", base::Name::SEPARATOR_S, base::Name::SEPARATOR_S);
    base::Name name(fullName.c_str());
    ASSERT_EQ(name.parts().size(), 3);
    ASSERT_EQ(name.parts()[0], "type");
    ASSERT_EQ(name.parts()[1], "name");
    ASSERT_EQ(name.parts()[2], "version");
}

TEST(NameTest, InitializationCopy)
{
    base::Name name ({"type", "name", "version"});
    base::Name copy(name);
    ASSERT_EQ(copy.parts().size(), 3);
    ASSERT_EQ(copy.parts()[0], "type");
    ASSERT_EQ(copy.parts()[1], "name");
    ASSERT_EQ(copy.parts()[2], "version");
}

TEST(NameTest, InitializationAssignment)
{
    base::Name name ({"type", "name", "version"});
    base::Name copy;
    copy = name;
    ASSERT_EQ(copy.parts().size(), 3);
    ASSERT_EQ(copy.parts()[0], "type");
    ASSERT_EQ(copy.parts()[1], "name");
    ASSERT_EQ(copy.parts()[2], "version");
}

TEST(NameTest, Equality)
{
    base::Name name1 ({"type", "name", "version"});
    base::Name name2 ({"type", "name", "version"});
    ASSERT_EQ(name1, name2);
}

TEST(NameTest, Distinct)
{
    // Version is different
    base::Name name1 ({"type", "name", "version"});
    base::Name name2 ({"type", "name", "version2"});
    ASSERT_NE(name1, name2);

    // Name is different
    base::Name name3 ({"type", "name2", "version"});
    ASSERT_NE(name1, name3);

    // Type is different
    base::Name name4 ({"type2", "name", "version"});
    ASSERT_NE(name1, name4);
}

TEST(NameTest, FullName)
{
    base::Name name ({"type", "name", "version"});
    ASSERT_EQ(name.fullName(),
              fmt::format("type{}name{}version",
                          base::Name::SEPARATOR_S,
                          base::Name::SEPARATOR_S));
}
#include "cipher/additive/additive.h"

#include <gtest/gtest.h>

// TEST(additive_cipher, init_test)
// {
//     EXPECT_EQ(1, 1);
// }

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class additive_test : public ::testing::Test
{
protected:
	void SetUp()
	{
		at = new additive;
	}

	void TearDown()
	{
		delete at;
	}

	additive *at;
};

TEST_F(additive_test, set_alphabet)
{
	at->set_alphabet("ABCD");
	ASSERT_EQ(at->get_alphabet(), "ABCD");

	at->set_alphabet("abcdefghijklmnopqrstuvwxyz");
	ASSERT_EQ(at->get_alphabet(), "abcdefghijklmnopqrstuvwxyz");

	at->set_alphabet("a");
	ASSERT_EQ(at->get_alphabet(), "a");

	at->set_alphabet("a1");
	ASSERT_EQ(at->get_alphabet(), "a1");
}

TEST_F(additive_test, set_source_text)
{
	at->set_source_text("source_text");
	ASSERT_EQ(at->get_source_text(), "source_text");
}

TEST_F(additive_test, set_cipher_text)
{
	at->set_cipher_text("cipher_text");
	ASSERT_EQ(at->get_cipher_text(), "cipher_text");
}

TEST_F(additive_test, encrypt)
{
	at->set_alphabet("abcdefghijklmnopqrstuvwxyz");

	at->set_source_text("savalione");
	at->set_key("0");
	at->encrypt();
	ASSERT_EQ(at->get_cipher_text(), "savalione");

	at->set_source_text("savalione");
	at->set_key("1");
	at->encrypt();
	ASSERT_EQ(at->get_cipher_text(), "tbwbmjpof");

	at->set_source_text("savalione");
	at->set_key("3809");
	at->encrypt();
	ASSERT_EQ(at->get_cipher_text(), "fninyvbar");
}
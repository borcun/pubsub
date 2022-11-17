#include "messageFactory.h"
#include <gtest/gtest.h>

#define MESSAGE_TOPIC_1   ("my-test-topic-1")
#define MESSAGE_TOPIC_2   ("my-test-topic-2")
#define MESSAGE_PAYLOAD_1 ("This is my first payload")
#define MESSAGE_PAYLOAD_2 ("This is my second payload")

TEST(MessageTest, SetterGetter) {
  Message message1 {MESSAGE_TOPIC_1};
  Message message2 {MESSAGE_TOPIC_1};
  Message message3 {MESSAGE_TOPIC_2};
  
  message1.setPayload(MESSAGE_PAYLOAD_1);
  message2.setPayload(MESSAGE_PAYLOAD_1);
  message3.setPayload(MESSAGE_PAYLOAD_2);
  
  EXPECT_EQ(message1.getTopic(), message2.getTopic());
  EXPECT_EQ(message1.getPayload(), message2.getPayload());  
  EXPECT_NE(message1.getTopic(), message3.getTopic());
  EXPECT_NE(message1.getPayload(), message3.getPayload());
}

int main(int argc, char**argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

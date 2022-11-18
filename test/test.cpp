#include "messageFactory.h"
#include "messageService.h"
#include "publisher.h"
#include "subscriber.h"
#include <gtest/gtest.h>

#define MESSAGE_TOPIC_1   ("my-test-topic-1")
#define MESSAGE_TOPIC_2   ("my-test-topic-2")
#define MESSAGE_PAYLOAD_1 ("This is my first payload")
#define MESSAGE_PAYLOAD_2 ("This is my second payload")

class Receiver : public Subscriber {
public:
  Receiver() {}
  Receiver(const std::string &name) : Subscriber(name) {}
  ~Receiver() {}
  void onReceived(const Message &message) {
    
  }
};

class Transmitter : public Publisher {
public:
  Transmitter() {}
  Transmitter(const std::string &name) : Publisher(name) {}
  ~Transmitter() {}
};

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

TEST(MessageFactoryTest, CreateMessage) {
  MessageFactory *messageFactory = MessageFactory::getInstance();

  Message message1 = messageFactory->createMessage(MESSAGE_TOPIC_1);
  Message message2 = messageFactory->createMessage(MESSAGE_TOPIC_1); 
  Message message3 = messageFactory->createMessage(MESSAGE_TOPIC_2);
  Message message4 = messageFactory->createMessage(MESSAGE_TOPIC_2);
  
  EXPECT_EQ(message1.getTopic(), message2.getTopic());
  EXPECT_NE(message1.getTopic(), message4.getTopic());
}

TEST(MessageService, Observer) {
  MessageFactory *messageFactory = MessageFactory::getInstance();
  Message message = messageFactory->createMessage(MESSAGE_TOPIC_1);
  MessageService messageService;
  Transmitter transmitter {"transmitter"};
  Receiver receiver {"receiver"};
  
  message.setPayload(MESSAGE_PAYLOAD_1);
  
  EXPECT_EQ(true, messageService.setMessage(&message));
  EXPECT_EQ(true, messageService.setPublisher(&transmitter));
  EXPECT_EQ(true, messageService.addSubscriber(&receiver));
  EXPECT_EQ(true, messageService.execute());
}

int main(int argc, char**argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

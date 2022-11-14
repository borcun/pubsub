#include "messageFactory.h"

#define MESSAGE_TOPIC_1  ("my-test-topic-1")
#define MESSAGE_TOPIC_2  ("my-test-topic-2")
#define MESSAGE_PAYLOAD_1 ("This is my first payload")
#define MESSAGE_PAYLOAD_2 ("This is my second payload")

int main() {
  MessageFactory *messageFactory = MessageFactory::getInstance();

  Message message1 = messageFactory->createMessage(MESSAGE_TOPIC_1);
  message1.setPayload(MESSAGE_PAYLOAD_1);
  Message message2 = messageFactory->createMessage(MESSAGE_TOPIC_1);

  std::cout << "message1: " << std::endl << message1 << std::endl;
  std::cout << "message2: " << std::endl << message2 << std::endl;
  
  Message message3 = messageFactory->createMessage(MESSAGE_TOPIC_2);
  message3.setPayload(MESSAGE_PAYLOAD_2);
  Message message4 = messageFactory->createMessage(MESSAGE_TOPIC_2);

  std::cout << "message3: " << std::endl << message3 << std::endl;
  std::cout << "message4: " << std::endl << message4 << std::endl;

  return 0;
}

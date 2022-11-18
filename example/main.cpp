#include "messageFactory.h"
#include "messageService.h"
#include "rssFeeder.h"
#include "rssReader.h"
#include <unistd.h>

#define MESSAGE_TOPIC_1       ("rss-topic-1")
#define MESSAGE_TOPIC_2       ("rss-topic-2")
#define MESSAGE_PAYLOAD_1     ("This is my first RSS payload")
#define MESSAGE_PAYLOAD_2     ("This is my second RSS payload")
#define MESSAGE_FEEDER        ("rss-feeder")
#define MESSAGE_READER_1      ("rss-reader-1")
#define MESSAGE_READER_2      ("rss-reader-2")

int main(int argc, char **argv) {
  Message message1 = MessageFactory::getInstance()->createMessage(MESSAGE_TOPIC_1);
  Message message2 = MessageFactory::getInstance()->createMessage(MESSAGE_TOPIC_2);
  RSSFeeder feeder  {MESSAGE_FEEDER};
  RSSReader reader1 {MESSAGE_READER_1};
  RSSReader reader2 {MESSAGE_READER_2};
  MessageService messageService;

  std::cout << "Two messages are created" << std::endl;
  std::cout << "Message 1" << std::endl << "---------" << std::endl << message1 << std::endl;
  std::cout << "Message 2" << std::endl << "---------" << std::endl << message2 << std::endl;
  
  std::cout << "MessageService is created" << std::endl;
  messageService.setPublisher(&feeder);
  std::cout << "\'" << feeder.getName() << "\' set into MessageService as publisher" << std::endl;
  message1.setPayload(MESSAGE_PAYLOAD_1);
  std::cout << "Message 1 payload is set to \'" << message1.getPayload() << "\'" << std::endl; 
  messageService.setMessage(&message1);
  std::cout << "\'" << message1.getTopic() << "\' set into MessageService as message" << std::endl;
  messageService.addSubscriber(&reader1);
  std::cout << "\'" << reader1.getName() << "\' set into MessageService as subscriber" << std::endl;
  std::cout << "MessageService is executed" << std::endl;
  messageService.execute();
  std::cout << "----------------------------" << std::endl;

  sleep(1);
  
  message1.setPayload(MESSAGE_PAYLOAD_2);
  std::cout << "Message 1 payload is set to \'" << message1.getPayload() << "\'" << std::endl; 
  messageService.setMessage(&message1);
  std::cout << "Message of MessageService is updated to \'" << message1.getTopic() << "\'" << std::endl;
  messageService.addSubscriber(&reader2);
  std::cout << "\'" << reader2.getName() << "\' set into MessageService as subscriber" << std::endl;
  std::cout << "MessageService is executed" << std::endl;
  messageService.execute();
  std::cout << "----------------------------" << std::endl;
  
  sleep(1);

  message2.setPayload(MESSAGE_PAYLOAD_2);
  std::cout << "Message 2 topic is set to \'" << message2.getPayload() << "\'" << std::endl;
  messageService.setMessage(&message2);
  std::cout << "Message of MessageService is updated to \'" << message2.getTopic() << "\'" << std::endl;
  std::cout << "MessageService is executed" << std::endl;
  messageService.execute();
  std::cout << "----------------------------" << std::endl;
  
  sleep(1);
  
  message2.setPayload(MESSAGE_PAYLOAD_1);
  std::cout << "Message 1 topic is set to \'" << message2.getPayload() << "\'" << std::endl;
  messageService.removeSubscriber(&reader1);
  std::cout << "\'" << reader1.getName() << "\' removed from MessageService" << std::endl;
  std::cout << "MessageService is executed" << std::endl;
  messageService.execute();

  return 0;
}

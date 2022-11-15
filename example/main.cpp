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
  Message message = MessageFactory::getInstance()->createMessage(MESSAGE_TOPIC_1);
  RSSFeeder feeder  {MESSAGE_FEEDER};
  RSSReader reader1 {MESSAGE_READER_1};
  RSSReader reader2 {MESSAGE_READER_2};
  MessageService messageService;

  std::cout << "MessageService is created" << std::endl;
  
  messageService.setPublisher(&feeder);
  std::cout << "A publisher (" << feeder.getName() << ") added into MessageService" << std::endl;
  message.setPayload(MESSAGE_PAYLOAD_1);
  messageService.setMessage(&message);
  std::cout << "A message (" << message.getTopic() << ") added into MessageService" << std::endl;
  messageService.addSubscriber(&reader1);
  std::cout << "A subscriber (" << reader1.getName() << ") added into MessageService" << std::endl;

  std::cout << "MessageService is executed" << std::endl;
  messageService.execute();
  sleep(1);
  
  message.setPayload(MESSAGE_PAYLOAD_2);
  messageService.setMessage(&message);
  std::cout << "The message (" << message.getTopic() << ") updated into MessageService" << std::endl;
  messageService.addSubscriber(&reader2);
  std::cout << "A subscriber (" << reader2.getName() << ") added into MessageService" << std::endl;

  std::cout << "MessageService is executed" << std::endl;
  messageService.execute();
  sleep(1);
  
  messageService.removeSubscriber(&reader1);
  std::cout << "A subscriber (" << reader1.getName() << ") removed from MessageService" << std::endl;

  std::cout << "MessageService is executed" << std::endl;
  messageService.execute();

  return 0;
}

#include "messageFactory.h"
#include "messageService.h"
#include "rssFeeder.h"
#include "rssReader.h"
#include <unistd.h>

#define MESSAGE_TOPIC_1       ("rss-topic-1")
#define MESSAGE_TOPIC_2       ("rss-topic-2")
#define MESSAGE_PAYLOAD_1     ("This is my first RSS payload")
#define MESSAGE_PAYLOAD_2     ("This is my second RSS payload")
#define MESSAGE_SERVICE       ("message-service")
#define MESSAGE_FEEDER        ("rss-feeder")
#define MESSAGE_READER_1      ("rss-reader-1")
#define MESSAGE_READER_2      ("rss-reader-2")

int main(int argc, char **argv) {
  MessageFactory *messageFactory = MessageFactory::getInstance();
  Message message = messageFactory->createMessage(MESSAGE_TOPIC_1);
  MessageService messageService {MESSAGE_SERVICE};
  RSSFeeder feeder  {MESSAGE_FEEDER};
  RSSReader reader1 {MESSAGE_READER_1};
  RSSReader reader2 {MESSAGE_READER_2};

  message.setPayload(MESSAGE_PAYLOAD_1);

  messageService.setMessage(&message);
  messageService.setPublisher(&feeder);
  messageService.subscribe(&reader1);

  messageService.execute();

  sleep(2);
  messageService.subscribe(&reader2);
  message.setPayload(MESSAGE_PAYLOAD_2);

  messageService.execute();
  
  return 0;
}

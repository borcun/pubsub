#include "topicFactory.h"
#include "rssFeeder.h"
#include "rssReader.h"
#include <thread>

#define READER_COUNT  (4)
#define FEEDER_COUNT  (4)

void feed(RSSFeeder feeder, Message message);

int main(int argc, char **argv) {
  Topic topic = TopicFactory::getInstance()->create();
  
  RSSReader readers[READER_COUNT] = {
    RSSReader("Reader-1"),
    RSSReader("Reader-2"),
    RSSReader("Reader-3"),
    RSSReader("Reader-4")
  };
  
  RSSFeeder feeders[FEEDER_COUNT] = {
    RSSFeeder("Feeder-1"),
    RSSFeeder("Feeder-2"),
    RSSFeeder("Feeder-3"),
    RSSFeeder("Feeder-4")
  };

  for (int i = 0; i < READER_COUNT; ++i) {
    topic.subscribe(&readers[i]);
  }

  for (int i = 0; i < FEEDER_COUNT; ++i) {
    feeders[i].setTopic(&topic);
  }

  std::cout << topic << std::endl;

  std::thread threads[FEEDER_COUNT] = {
    std::thread(feed, feeders[0], Message("Message from Feeder-1")),
    std::thread(feed, feeders[1], Message("Message from Feeder-2")),
    std::thread(feed, feeders[2], Message("Message from Feeder-3")),
    std::thread(feed, feeders[3], Message("Message from Feeder-4"))
  };

  for (int i = 0; i < FEEDER_COUNT; ++i) {
    threads[i].join();
  }
  
  return 0;
}
		
void feed(RSSFeeder feeder, Message message) {
  for (int i = 0; i < 3; ++i) {
    feeder.notify(message);
  }
  
  return;
}

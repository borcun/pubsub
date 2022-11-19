#include "topicFactory.h"
#include "rssFeeder.h"
#include "rssReader.h"
#include <thread>

#define FEEDER_COUNT       (10)

Topic topic = TopicFactory::getInstance()->create();

void feed(RSSFeeder feeder, Message message) {
  for (int i = 0; i < 10; ++i) {
    feeder.notify(message);
  }
}

int main(int argc, char **argv) {
  RSSReader reader {"rss-reader"};
  Message messages[FEEDER_COUNT];
  // feeder list
  RSSFeeder feeders[FEEDER_COUNT] = {
    RSSFeeder("message-feeder-1"),
    RSSFeeder("message-feeder-2"),
    RSSFeeder("message-feeder-3"),
    RSSFeeder("message-feeder-4"),
    RSSFeeder("message-feeder-5"),
    RSSFeeder("message-feeder-6"),
    RSSFeeder("message-feeder-7"),
    RSSFeeder("message-feeder-8"),
    RSSFeeder("message-feeder-9"),
    RSSFeeder("message-feeder-10")
  };
  //! messages payloads
  std::string payloads[FEEDER_COUNT] = {
    "message-1",
    "message-2",
    "message-3",
    "message-4",
    "message-5",
    "message-6",
    "message-7",
    "message-8",
    "message-9",
    "message-10"
  };
  
  topic.subscribe(&reader);

  for (int i = 0; i < FEEDER_COUNT; ++i) {
    messages[i].setPayload(payloads[i]);
    feeders[i].setTopic(&topic);
  }

  std::thread threads[FEEDER_COUNT] = {
    std::thread(feed, feeders[0], messages[0]),
    std::thread(feed, feeders[1], messages[1]),
    std::thread(feed, feeders[2], messages[2]),
    std::thread(feed, feeders[3], messages[3]),
    std::thread(feed, feeders[4], messages[4]),
    std::thread(feed, feeders[5], messages[5]),
    std::thread(feed, feeders[6], messages[6]),
    std::thread(feed, feeders[7], messages[7]),
    std::thread(feed, feeders[8], messages[8]),
    std::thread(feed, feeders[9], messages[9])
  };

  for (int i = 0; i < FEEDER_COUNT; ++i) {
    threads[i].join();
  }
  
  return 0;
}

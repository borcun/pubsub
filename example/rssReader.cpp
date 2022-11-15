#include "rssReader.h"

RSSReader::RSSReader(void) {

}

RSSReader::RSSReader(const std::string &name) : Subscriber(name) {

}

RSSReader::~RSSReader() {

}

void RSSReader::onReceived(Message &message) {
  std::cout << "Received message by " << getName() << std::endl;
  std::cout << message << std::endl;
}

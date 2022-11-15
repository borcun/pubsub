#include "publisher.h"

Publisher::Publisher(void) : m_name(DEFAULT_PUBLISHER_NAME) {
}

Publisher::Publisher(const std::string &name) : m_name(name) {
}

Publisher::~Publisher() {
  m_subscribers.clear();
}

void Publisher::setName(const std::string &name) {
  m_name = name;
  return;
}

std::string Publisher::getName(void) const {
  return m_name;
}

bool Publisher::subscribe(Subscriber *subscriber) {  
  if (contains(subscriber)) {
    return false;
  }
  
  m_subscribers.push_back(subscriber);
  return true;
}

void Publisher::unsubscribe(Subscriber *subscriber) {
  if (contains(subscriber)) {
    m_subscribers.remove(subscriber);	
  }
  
  return;
}

void Publisher::notify(Message &message) {
  std::list<Subscriber *>::iterator it;
    
  for (it = m_subscribers.begin(); it != m_subscribers.end(); ++it) {
    (*it)->onReceived(message);
  }

  return;
}

bool Publisher::contains(const Subscriber *subscriber) {
  if (nullptr == subscriber) {
    return false;
  }

  std::list<Subscriber *>::iterator it;
  bool isContained = false;
    
  for (it = m_subscribers.begin(); it != m_subscribers.end() && !isContained; ++it) {
    if (subscriber->getName() == (*it)->getName()) {
      isContained = true;
    }
  }

  return isContained;
}

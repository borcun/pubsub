#include "topic.h"

unsigned int Topic::m_id = 0;

Topic::Topic(void) {
  ++m_id;
}

Topic::Topic(const Topic &topic) {

}

Topic::~Topic() {
  m_subscribers.clear();
}

unsigned int Topic::getId(void) {
  return m_id;
}

bool Topic::subscribe(Subscriber *subscriber) {
  std::list<Subscriber *>::iterator it;
  bool isSubscribed = false;
    
  for (it = m_subscribers.begin(); it != m_subscribers.end() && !isSubscribed; ++it) {
    if (subscriber == *it) {
      isSubscribed = true;
    }
  }

  if (!isSubscribed) {
    m_subscribers.push_back(subscriber);
  }

  return !isSubscribed;
}

bool Topic::unsubscribe(Subscriber *subscriber) {
  std::list<Subscriber *>::iterator it;
  bool isSubscribed = false;
    
  for (it = m_subscribers.begin(); it != m_subscribers.end() && !isSubscribed; ++it) {
    if (subscriber == *it) {
      isSubscribed = true;
    }
  }

  if (isSubscribed) {
    m_subscribers.remove(*it);
  }
  
  return isSubscribed;
}

void Topic::publish(const Message &message) {
  std::list<Subscriber *>::iterator it;

  std::unique_lock lock(m_mutex);

  for (it = m_subscribers.begin(); it != m_subscribers.end(); ++it) {
    (*it)->onReceived(message);
  }
  
  return;
}

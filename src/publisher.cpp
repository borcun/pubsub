#include "publisher.h"

Publisher::Publisher(const std::string &name) : m_name(name) {
  m_topic = nullptr;
}

Publisher::~Publisher() {
  m_topic = nullptr;
}

std::string Publisher::getName(void) const {
  return m_name;
}

void Publisher::setTopic(Topic *topic) {
  m_topic = topic;
  return;
}

bool Publisher::operator==(const Publisher &publisher) {
  return publisher.m_name == m_name;
}

bool Publisher::operator!=(const Publisher &publisher) {
  return publisher.m_name != m_name;
}

void Publisher::notify(Message message) {
  if (nullptr != m_topic) {
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    message.setTime(tv);
    m_topic->publish(message);
  }
  
  return;
}

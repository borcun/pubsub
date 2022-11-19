#include "topicFactory.h"

TopicFactory *TopicFactory::m_instance = nullptr;

TopicFactory::~TopicFactory() {
  if (nullptr != m_instance) {
    delete m_instance;
  }

  m_topics.clear();
}

TopicFactory *TopicFactory::getInstance(void) {
  if (nullptr == m_instance) {
    m_instance = new TopicFactory();
  }

  return m_instance;
}

Topic TopicFactory::create(void) {
  Topic topic;
  
  m_topics.insert({topic.getId(), topic});

  return topic;
}

bool TopicFactory::contains(Topic &topic) {
  return m_topics.end() != m_topics.find(topic.getId());
}

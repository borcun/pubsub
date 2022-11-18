#include "messageService.h"

MessageService::MessageService(void) {
  m_message = nullptr;
  m_publisher = nullptr;
}

MessageService::~MessageService() {

}

bool MessageService::setMessage(Message *message) {
  if (nullptr == message) {
    return false;
  }
  
  m_message = message;

  return true;
}

bool MessageService::setPublisher(Publisher *publisher) {
  if (nullptr == publisher) {
    return false;
  }
  
  m_publisher = publisher;

  return true;
}

bool MessageService::addSubscriber(Subscriber *subscriber) {
  if (nullptr == m_publisher) {
    return false;
  }
  
  return m_publisher->subscribe(subscriber);
}

void MessageService::removeSubscriber(Subscriber *subscriber) {
  if (nullptr != m_publisher) {
    m_publisher->unsubscribe(subscriber);
  }
  
  return;
}

bool MessageService::execute(void) {
  if (nullptr == m_message || nullptr == m_publisher) {
    return false;
  }

  m_publisher->notify(*m_message);
  return true;
}

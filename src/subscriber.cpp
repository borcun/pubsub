#include "subscriber.h"

Subscriber::Subscriber(void) : m_name(DEFAULT_SUBSCRIBER_NAME) {

}

Subscriber::Subscriber(const std::string &name) : m_name(name) {

}

Subscriber::~Subscriber() {

}

void Subscriber::setName(const std::string &name) {
  m_name = name;
  return;
}

std::string Subscriber::getName(void) const {
  return m_name;
}

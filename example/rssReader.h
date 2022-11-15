#ifndef RSS_READER_H
#define RSS_READER_H

#include "subscriber.h"
#include "message.h"

class RSSReader : public Subscriber {
 public:
  RSSReader(void);
  RSSReader(const std::string &name);
  ~RSSReader();
  virtual void onReceived(Message &message);
};

#endif

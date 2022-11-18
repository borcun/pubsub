/**
 * @file subscriber.h
 * @brief base subscriber class, also an abstract class
 * @author B. Orcun Ozkablan
 */

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "message.h"

//! default subscriber name which is used unless user sets subscriber name
#define DEFAULT_SUBSCRIBER_NAME ("subscriber")

class Subscriber {
 public:
  /**
   * @brief default constructor
   */
  Subscriber(void);

  /**
   * @brief constructor
   * @param [in] name - name of subscriber
   */
  Subscriber(const std::string &name);

  /**
   * @brief destructor
   */  
  virtual ~Subscriber();

  /**
   * @brief function that sets name of subscriber
   * @param [in] name - name of subscriber
   * @return -
   */  
  void setName(const std::string &name);

  /**
   * @brief function that sets name of subscriber
   * @param [in] name - name of subscriber
   * @return -
   */  
  std::string getName(void) const;

  /**
   * @brief function that is triggered when message's publisher notify
   * @param [in] message - Message instance send by Publisher inside the same context
   * @return -
   */
  virtual void onReceived(const Message &message) = 0;

 private:
  //! name of subscriber
  std::string m_name;
};

#endif

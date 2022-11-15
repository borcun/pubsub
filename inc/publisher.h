/**
 * @file publisher.h
 * @brief base publisher class, constructed by using observer design pattern
 * @author B. Orcun Ozkablan
 */

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "subscriber.h"
#include <list>

//! default publisher name which is used unless user sets publisher name
#define DEFAULT_PUBLISHER_NAME ("publisher")

/**
 * @class Publisher
 */
class Publisher {
 public:
  /**
   * @brief default constructor
   */
  Publisher(void);

  /**
   * @brief constructor
   * @param [in] name - name of publisher
   */
  Publisher(const std::string &name);

  /**
   * @brief destructor
   */  
  virtual ~Publisher();

  /**
   * @brief function that sets name of publisher
   * @param [in] name - name of publisher
   * @return -
   */  
  void setName(const std::string &name);

  /**
   * @brief function that sets name of publisher
   * @param [in] name - name of publisher
   * @return -
   */  
  std::string getName(void) const;

  /**
   * @brief function that subscribes Subscriber object into subscriber list
   * @param [in] subscriber - Subscriber reference
   * @return true if it's subscribed. Otherwise, return false
   */  
  virtual bool subscribe(Subscriber *subscriber) final;

  /**
   * @brief function that unsubscribes Subscriber object from subscriber list
   * @param [in] subscriber - Subscriber object
   * @return -
   * @remark function does not throw any exception unless even the object was into the list
   */  
  virtual void unsubscribe(Subscriber *subscriber) final;

  /**
   * @brief function that notifies its all subscribers with Message object
   * @param [in] message - Message object to be sent to the subscribers
   * @return -
   */  
  virtual void notify(Message &message) final;
  
 private:
  //! name of publisher
  std::string m_name;
  //! subscriber list
  std::list<Subscriber *> m_subscribers;

  /**
   * @brief function that gets whether subscriber is into Subscriber list
   * @param [in] subscriber - Subscriber object
   * @return true if the object was into the list. Otherwise, return false.
   */
  bool contains(const Subscriber *subscriber);
};

#endif

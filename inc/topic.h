/**
 * @file topic.h
 * @brief topic class
 * @author B. Orcun Ozkablan
 */

#ifndef TOPIC_H
#define TOPIC_H

#include <list>
#include <mutex>
#include <shared_mutex>
#include "subscriber.h"

/**
 * @class Topic
 */
class Topic {
public:
  /**
   * @brief default constructor
   */
  Topic(void);

  /**
   * @brief copy constructor
   * @param [in] topic - Topic reference
   */
  Topic(const Topic &topic);

  /**
   * @brief destructor
   */
  virtual ~Topic();

  /**
   * @brief function that gets topic id
   * @return topic id
   * @remark topic id is unique for each topic within process
   */
  virtual unsigned int getId(void) final;

  /**
   * @brief function that register a subscriber to the topic
   * @param [in] subscsriber - Subscriber pointer
   * @return true if the subscribers is added into the list. Otherwise, return false.
   */
  bool subscribe(Subscriber *subscriber);

  /**
   * @brief function that unsubscribes subscriber from the topic
   * @param [in] subscsriber - Subscriber pointer
   * @return true if the subscribers is removed from the list. Otherwise, return false.
   */
  bool unsubscribe(Subscriber *subscriber);

  /**
   * @brief function that publishes message to all subscribers
   * @return -
   */
  void publish(const Message &message);

private:  
  //! subscriber list
  std::list<Subscriber *> m_subscribers;

  //! topic id
  static unsigned int m_id;

  //! mutex for publishing by publisher more than one
  mutable std::shared_mutex m_mutex;
};

#endif

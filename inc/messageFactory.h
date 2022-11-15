/**
 * @file messageFactory.h
 * @brief singleton message factory class, which is also implemented as a factory method creating unique amessage instance
 * @author B. Orcun Ozkablan
 */

#ifndef MESSAGE_FACTORY_H
#define MESSAGE_FACTORY_H

#include <list>
#include "message.h"

/**
 * @class MessageFactory
 */
class MessageFactory {
 public:
  /**
   * @brief function that gets class instance
   * @return MessageFactory pointer
   */
  static MessageFactory *getInstance(void);

  /**
   * @brief destructor
   */
  virtual ~MessageFactory();

  /**
   * @brief function that creates a Message instance
   * @param [in] topic - topic of Message instance to be created
   * @return Message instancex
   */
  Message createMessage(const std::string &topic);

  /**
   * @brief function that checks whether Message instance is into message list
   * @param [in] message - Message reference
   * @return true if the Message instance is in message list. Otherwise, return false.x
   */
  bool contains(const Message &message);

 private:
  //! class pointer
  static MessageFactory *m_instance;
  //! list of messages created
  std::list<Message> m_messageList;

  //! default constructor
  MessageFactory(void) = default;
  //! copy constructor
  MessageFactory(const MessageFactory &messageFactory) = delete;
  //! copy assignment operator
  MessageFactory &operator=(const MessageFactory &messageFactory) = delete;
};

#endif

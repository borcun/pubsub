/**
 * @file messageService.h
 * @brief message service class
 * @author B. Orcun Ozkablan
 */

#ifndef MESSAGE_SERVICE_H
#define MESSAGE_SERVICE_H

#include "message.h"
#include "subscriber.h"
#include "publisher.h"

/**
 * @class MessageService
 */
class MessageService {
 public:
  /**
   * @brief default constructor
   */
  MessageService(void);

  /**
   * @brief destructor
   */
  virtual ~MessageService();

  /**
   * @brief function that sets data (message) of message service
   * @param [in] message - Message pointer
   * @return -
   */
  void setMessage(Message *message);

  /**
   * @brief function that sets publisher of message service
   * @param [in] publisher - Publisher pointer
   * @return -
   */
  void setPublisher(Publisher *publisher);

  /**
   * @brief function that adds a Subscriber to message service
   * @param [in] subscsriber - Subscriber pointer
   * @return -
   */
  bool addSubscriber(Subscriber *subscriber);

  /**
   * @brief function that removes Subscriber to message service
   * @param [in] subscsriber - Subscriber pointer
   * @return -
   */
  void removeSubscriber(Subscriber *subscriber);

  /**
   * @brief function that executes message service
   * @return true if the message service executes successfully. Otherwise, return false.
   */
  bool execute(void);

 private:
  //! Message instance of the message service
  Message *m_message;
  //! Publisher pointer
  Publisher *m_publisher;
};

#endif

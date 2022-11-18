### About Library

It is a small publisher-subscriber library, which is developed on Fedora OS for Intel x64 architecture.
The library includes four important concepts:

 1. Message
 2. MessageFactory
 3. Publisher & Subscriber
 4. Message Service

Message is the basic data model, which exists from topic, time label and payload fields. The topic is
a string and must be unique within your projects. It is used to make Message instance as unique either.
The time label is struct timeval instance of the any UNIX system. It is used to reveal the time when
the payload of Message instance is set. Therefore, it is set once the payload is set. The last field,
the payload is data part of Message instance. It's designed as a string like topic.

MessageFactory is a class that is designed as factory design pattern. It generates custom messages
according to topic given by developer and stores the messages into a message list. Storing the messages
into a message list, it can check any willness of regeneration of any message again. Therefore, it can
provides uniqueness of each message.

Publisher and Subscriber classes are communication components of the library. Knowing from observer
design pattern, these components provides event-based communication instead of polling mechanism.
Sharing data between them is Message intances. Message instances created by MessageFactory are shared
from one publisher to many subscribers, which are connected together within special context.

MessageService class exists from one Message instance, one Publisher instance and many Subscriber
instances. After setting fields of a MessageService instance, you can execute it to perform message
delivering according to publish-subscribe principle.

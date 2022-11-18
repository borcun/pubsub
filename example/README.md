### About Example

After building the library, the example is automatically built. Thus, you do not need to build it independently.
The following steps are about the example flow.

- Two different messages are created by using two topics: Message 1 and Message 2
- One publisher is created: RSS Feeder 
- Two subscribers are created: RSS Reader 1 and RSS Reader 2
- One MessageService is created: MessageService

After initializations are done, test algorithms executes.

1. Message 1, RSS Feeder and RSS Reader 1 are included into MessageService. Then, MessageService is executed.
2. Message 1 payload is updated. RSS Reader 2 is included into MessageService. Then, MessageService is executed.
3. Message 2 is placed into MessageService instead of Message 1. Then, MessageService is executed.
4. Message 2 payload is updated. RSS Reader 1 is removed from MessageService. Then, MessageService is executed.

After each step, dash lines are printed and one second is delayed.


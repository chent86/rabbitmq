#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string queue = "hi";
  AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();
  channel->DeclareQueue(queue, false, true, false, false);
  string str = "hi!";
 channel->BasicPublish("", queue, AmqpClient::BasicMessage::Create(str));
  cout << "sent hello world";
}
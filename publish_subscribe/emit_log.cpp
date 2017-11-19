#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>
using namespace std;
using namespace AmqpClient;
int main() {
  while(1) {
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();
    channel->DeclareExchange("logs", "fanout");
    string str;
    cin >> str;
    channel->BasicPublish("logs", "", AmqpClient::BasicMessage::Create(str));
    cout << "sent " << str << endl;
  }
}
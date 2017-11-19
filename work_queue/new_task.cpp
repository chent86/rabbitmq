#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>
using namespace std;
using namespace AmqpClient;
int main() {
  while(1) {
    string queue = "task_queue";
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();
    channel->DeclareQueue(queue, false, true, false, false);
    string str;
    cin >> str;
    channel->BasicPublish("", queue, AmqpClient::BasicMessage::Create(str));
    cout << "sent " << str << endl;
  }
}
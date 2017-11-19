#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
  while(1) {
    string queue = "hello";
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create("192.168.199.229", 5672, "remote", "123456");
    channel->DeclareQueue(queue, false, true, false, false);
    AmqpClient::Envelope::ptr_t envelope;
    channel->BasicConsume(queue, "", true, true, false);
    bool success = channel->BasicConsumeMessage(envelope, -1);
    string buffer = envelope->Message()->Body();
    cout << buffer << endl;    
  }
}
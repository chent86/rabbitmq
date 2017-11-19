#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace AmqpClient;
int main() {
  while(1) {
    string queue = "task_queue";
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();
    channel->DeclareQueue(queue, false, true, false, false);
    AmqpClient::Envelope::ptr_t envelope;
    channel->BasicConsume(queue, "", true, false, false);
    bool success = channel->BasicConsumeMessage(envelope, -1);
    string buffer = envelope->Message()->Body();
    sleep(5);
    cout << buffer << endl;
    channel->BasicAck(envelope);
  }
}
#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>
using namespace std;
using namespace AmqpClient;
int main() {
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();
    channel->DeclareExchange("logs", "fanout");
    AmqpClient::Envelope::ptr_t envelope;
    string queue_name = channel->DeclareQueue("");
    channel->BindQueue(queue_name, "logs", "");
    channel->BasicConsume(queue_name , "", true, true, false);
    bool success = channel->BasicConsumeMessage(envelope, -1);
}

//sudo rabbitmqctl list_bindings  可以查看bind 情况

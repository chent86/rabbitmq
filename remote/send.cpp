#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string queue = "hello";
  AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create("192.168.199.229", 5672, "remote", "123456");  //host即为跑recv.cpp代码的电脑的ip地址
              // 在linux下可通过指令ifconfig查看
  channel->DeclareQueue(queue, false, true, false, false);
  string str = "hello!";
 channel->BasicPublish("", queue, AmqpClient::BasicMessage::Create(str));
  cout << "sent hello";
}
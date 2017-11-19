import pika
while(1):
  connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
  channel = connection.channel()

  channel.queue_declare(queue='666')
  message = raw_input("please enter what you want: ")
  channel.basic_publish(exchange='',
                        routing_key='666',
                        body = message)
  print(" [x] Sent 'Hello World!'")
  connection.close()
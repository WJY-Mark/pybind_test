import my_module
# from message_pb2 import MyMessage

# Create a new MyMessage
input_message = my_module.MyMessage()
input_message.id = 1
input_message.content = "Hello, World!"

# Debugging: Print the type of input_message
print(type(input_message))  # Should be <class 'my_module.MyMessage'>

# Call the C++ function
output_message = my_module.process_message(input_message)
print(type(output_message))  # Should be <class 'my_module.MyMessage'>

# Print the output
print(f"Output ID: {output_message.id}, Content: {output_message.content}")
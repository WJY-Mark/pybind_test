#include <pybind11/pybind11.h>
#include "message.pb.h"
#include "knot.h"

namespace py = pybind11;

MyMessage process_message(const MyMessage& input) {
    MyMessage output;
    Knot k(input.id(), input.id() + 3);
    int add_up = k.add_up();
    output.set_id(add_up);  // Example processing: incrementing the ID
    output.set_content("Processed: " + input.content());
    return output;
}

PYBIND11_MODULE(my_module, m) {
    m.def("process_message", &process_message, "Process a MyMessage and return a new MyMessage");
    py::class_<MyMessage>(m, "MyMessage")
        .def(py::init<>())  // Default constructor
        .def_property("id", &MyMessage::id, &MyMessage::set_id)
        .def_property("content", 
                      (const std::string&(MyMessage::*)() const)&MyMessage::content, 
                      (void(MyMessage::*)(const std::string&))&MyMessage::set_content)
        .def("SerializeToString", &MyMessage::SerializeToString)
        .def("ParseFromString", &MyMessage::ParseFromString);
}

// PYBIND11_MODULE(my_module, m) {
//   py::class_<MyMessage>(m, "MyMessage")
//       .def(py::init<>())                   // 默认构造函数
//       .def_readwrite("id", &MyMessage::id) // 读写属性 id
//       .def_readwrite("content", &MyMessage::content);
// }
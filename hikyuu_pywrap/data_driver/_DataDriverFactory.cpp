/*
 *  Copyright (c) hikyuu.org
 *
 *  Created on: 2020-6-14
 *      Author: fasiondog
 */

#include <hikyuu/indicator/build_in.h>
#include <pybind11/pybind11.h>
#include <hikyuu/data_driver/DataDriverFactory.h>
#include "_KDataDriver.h"

using namespace hku;
namespace py = pybind11;

void export_DataDriverFactory(py::module& m) {
    py::class_<DataDriverFactory>(m, "DataDriverFactory")
      .def_static("getBaseInfoDriver", &DataDriverFactory::getBaseInfoDriver)
      .def_static("regBaseInfoDriver", &DataDriverFactory::regBaseInfoDriver)
      .def_static("removeBaseInfoDriver", &DataDriverFactory::removeBaseInfoDriver)
      .def_static("getKDataDriver", &DataDriverFactory::getKDataDriver)
      .def_static("removeKDataDriver", &DataDriverFactory::removeKDataDriver)
      .def_static("getBlockDriver", &DataDriverFactory::getBlockDriver)
      .def_static("regBlockDriver", &DataDriverFactory::regBlockDriver)
      .def_static("removeBlockDriver", &DataDriverFactory::removeBlockDriver)

      .def_static("regKDataDriver",
                  [](py::object pydriver) {
                      auto keep_python_state_alive = std::make_shared<py::object>(pydriver);
                      auto ptr = pydriver.cast<PyKDataDriver*>();
                      auto driver = KDataDriverPtr(keep_python_state_alive, ptr);
                      DataDriverFactory::regKDataDriver(driver);
                  })

      ;
}

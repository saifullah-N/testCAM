/******************************************************************************\

  CAMotics is an Open-Source simulation and CAM software.
  Copyright (C) 2011-2019 Joseph Coffland <joseph@cauldrondevelopment.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#include "python/PyPlanner.h"

#include <cbang/log/Logger.h>


static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT, "gplan", 0, -1, 0, 0, 0, 0, 0
};


PyMODINIT_FUNC PyInit_gplan() {
  // Configure logger
  cb::Logger::instance().setLogTime(false);
  cb::Logger::instance().setLogShortLevel(true);
  cb::Logger::instance().setLogColor(false);
  cb::Logger::instance().setLogPrefix(true);

  PyObject *m = PyModule_Create(&module);
  if (!m) return 0;

  if (0 <= PyType_Ready(&PlannerType)) {
    Py_INCREF(&PlannerType);
    PyModule_AddObject(m, "Planner", (PyObject *)&PlannerType);
  }

  return m;
}

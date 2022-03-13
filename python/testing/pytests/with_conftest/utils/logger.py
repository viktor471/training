import inspect
from ctypes import c_int64


# TODO automatically receive fixture parameters

class Params:

    def __init__(self, position=None, type=None, autouse=None, scope=None, msg=None):
        self.position = position
        self.type = type
        self.autouse = autouse
        self.scope = scope
        self.msg = msg
        self.log_string = ""
        self._padding = 0

    def append_alignment_string(self, value, alignment=10):
        if value is not None:
            self.log_string += f" {value:<{alignment}}"
        else:
            self.log_string += f" {'':<{alignment}}"

        self._padding += alignment

    def accept_log_string(self, log_string):
        self.log_string = log_string
        self.append_alignment_string(self.position)

        if self.type is None:
            self.append_alignment_string("fixture", 13)
        else:
            self.append_alignment_string(self.type, 13)

        if self.autouse is None:
            self.append_alignment_string("")
        else:
            self.append_alignment_string("autouse")

        self.append_alignment_string(self.scope)
        self.append_alignment_string(self.msg)
        return self._padding, f"{self.log_string}:"


class Logger:
    _exec_order = []
    _arbitrary_log = []
    _exec_number = 0
    _padding = c_int64(0)

    def __init__(self, log_name="default"):
        self.file = open(f"{log_name}.log", "w")
        self._log_string = ""

    def __del__(self):
        new_partition = "\n\n\n=================\n"
        self.file.write(new_partition)
        self.file.write("exec order: \n\n")
        self.file.writelines(self._exec_order)
        self.file.write(new_partition)
        self.file.write("arbitrary log: \n\n")
        self.file.writelines(self._arbitrary_log)
        self.file.close()

    def _insert_params(self, params):
        if params is not None:
            self._padding.value, self._log_string = params.accept_log_string(self._log_string)

    def _append_name_of_function(self, name_of_function):
        if name_of_function is None:
            name_of_function = inspect.stack()[2][3]

        if "fixture" in self._log_string:
            self._exec_order.append(self._log_string + name_of_function + "\n")
        else:
            # TODO analyze where from does come 5 shift
            padding = f"{'':>{self._padding.value + 5}}"
            name_of_function = ' ' + name_of_function
            self._exec_order.append(f"{padding}{name_of_function} \n")

    def record_exec_order(self, params=None, msg=None, name_of_function=None,
                          position=None, type=None, autouse=None, scope=None):
        if msg is not None:
            self._log_string += f"{msg}"

        if params is None:
            condition = position is not None \
                        or type is not None \
                        or autouse is not None \
                        or scope is not None

            if condition:
                params = Params(type=type, scope=scope, autouse=autouse, position=position)

        self._insert_params(params)
        self._append_name_of_function(name_of_function)

    def record_arbitrary_log(self, msg: str, add_to_exec_log=False, params=None):
        self._arbitrary_log.append(msg + "\n")
        if add_to_exec_log:
            self.record_exec_order(params, msg, inspect.stack()[1][3])

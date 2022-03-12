import inspect

class Logger:
    _exec_order = []
    
    def __init__(self, logname="default"):
        self.file = open(f"{logname}.log", "w")
    
    def __del__(self):
        self.file.write("exec order:\n")
        self.file.writelines(self._exec_order)
        self.file.close()
    
    def record_exec_order(self):
        self._exec_order.append(inspect.stack()[1][3])
        print(self._exec_order)

def logger():
    return Logger() 

def func_1():
    logger().record_exec_order()

def func_2():
    logger().record_exec_order()
    func_1()

def func_3():
    Logger().record_exec_order()
    func_2()

func_3()
print(Logger()._exec_order)

help(open("file"))
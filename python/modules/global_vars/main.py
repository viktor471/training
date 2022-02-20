import vars

gl_local_var = 77
print(vars.gl_var_1)

def print_gl_var():
    print(vars.gl_var_1)

def print_gl_l_var():
    global gl_local_var
    print(gl_local_var)
    gl_local_var = gl_local_var + 1
    print(gl_local_var)

print_gl_var()

print_gl_l_var()
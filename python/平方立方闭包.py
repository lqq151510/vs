def exe(exp):
    def epr(lo):
        return lo**exp
    return epr
square = exe(2)
cube = exe(3)
print(square(2))
print(cube(2))

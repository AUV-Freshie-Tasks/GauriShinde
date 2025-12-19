import pidBind

from pidBind import proportionalController, integralController, derivativeController, pidController

print("Proportional Control")
p = proportionalController(2)
p.set_Kp(4)
a = p.get_Kp()
print(f"Kp: {a}")
print(p.computePaction(2))

print("Integral Control")
i = integralController(4)
i.set_Ki(2)
b = i.get_Ki()
print(f"Ki: {b}")
for I in range(5):
    print(i.computeIaction(2.0))

i.eraseIntegral()
print(i.computeIaction(2))
i.eraseIntegral()

print("Derivative Control")
d = derivativeController(2)
d.set_Kd(3)
c = d.get_Kd()
print(f"Kd: {c}")
for I in range(5):
    print(d.computeDaction(2))
d.resetOldError()


print("Testing pid Controller")
pid = pidController(1,1,1)
pid.set_Kp(4)
pid.set_Ki(2)
pid.set_Kd(3)
print(f"Kp: {pid.get_Kp()}   Ki: {pid.get_Ki()}   Kd: {pid.get_Kd()}")
error = 3
for j in range(5):
    print(f"--{j}--")
    print(p.computePaction(error))
    print(i.computeIaction(error))
    print(d.computeDaction(error))
    print(pid.computePIDaction(error))


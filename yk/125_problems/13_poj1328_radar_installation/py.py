import random
import subprocess
def update_in():
  s=""
  s+="{} {}\n".format(3,10)
  for _ in range(3):
    r0=random.randint(-10,10)
    r1=random.randint(0,10)
    s+="{} {}\n".format(r0, r1)
  s+="{} {}\n".format(0,0)
  with open("in_py","w")as f:
    f.write(s)
for _ in range(10):
  update_in()
  command="./ac.out < in_py"
  output=subprocess.check_output(command,shell=True)
  output0=output.decode("utf-8").strip()
  command="./a.out < in_py"
  output=subprocess.check_output(command,shell=True)
  output1=output.decode("utf-8").strip()
  if output0==output1:
    is_same="same"
  else:
    is_same="different"
  # if is_same!="same":
  print(is_same+" "+output0+","+output1)
  if is_same=="different":
    break

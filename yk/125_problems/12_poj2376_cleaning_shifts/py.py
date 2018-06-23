import random
import subprocess
def update_in():
  s=""
  s+="{} {}\n".format(10, 20)
  n_min=1;
  n_max=20;
  for _ in range(10):
    r0=random.randint(n_min,n_max)
    r1=random.randint(n_min,n_max)
    if r0>r1:
      r0,r1=r1,r0
    s+="{} {}\n".format(r0, r1)
  with open("in_py","w")as f:
    f.write(s)
for _ in range(300):
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
  if is_same!="same":
    print(is_same+" "+output0+","+output1)

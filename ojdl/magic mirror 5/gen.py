import random

with open(f'1.in','w') as F:
	F.write('520')
for i in range(2,10+1):
	with open(f'{i}.in','w') as F:
		F.write(str(i+10))

for i in range(11,20+1):
	with open(f'{i}.in','w') as F:
		F.write(str(random.randint(4500,5000)))

for i in range(21,40+1):
	with open(f'{i}.in','w') as F:
		F.write(str(random.randint(150000000,200000000)))

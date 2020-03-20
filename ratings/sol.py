import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

def tot_ncr(n, d):
	tot = 0
	for i in range(0, n + 1):
		tot += ncr(i + d - 1, d - 1)
		print("n", i + d - 1,"k", d - 1,"ncr",ncr(i + d - 1,d - 1))
	return tot

while True:
	x = raw_input()
	if x == '0':
		break
	ratings = map(int, x.split(" "))
	ratings = ratings[1:]	
	n = sum(ratings)
	d = len(ratings)
	# x_1 + x_2 + .. + x_d = 0, 1,2, ..., n
	tri = tot_ncr(n,d)
	sub = 0	
	for r in ratings:
		n_temp = n
		n_temp -= (r + 1)
		if n_temp < 0:
			break
		sub += ncr(n_temp + d - 1, d - 1)			
		n -= r
		d -= 1

		
	print(tri - sub)

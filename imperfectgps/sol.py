from math import sqrt 

n,delta_t = map(int, raw_input().split(" "))
x,y,t = map(int, raw_input().split(" "))
last_point = (x,y,t)
last_gps = (x,y,t)
real_dist = 0
gps_dist = 0
last_gps_index = 0

for i in range(1, n):	
	x,y,t = map(int, raw_input().split(" "))
	time_diff = t - last_point[2]	
	real_dist += sqrt((last_point[0] - x)**2 + (last_point[1] - y)**2)
	
	gps_index = t // delta_t	
	
	for j in range(last_gps_index + 1, gps_index + 1):
		gps_t = j*delta_t	
		gps_x = last_point[0] + (float(gps_t - last_point[2]) / time_diff) * (x - last_point[0])
		gps_y = last_point[1] + (float(gps_t - last_point[2]) / time_diff) * (y - last_point[1])
		gps_dist += sqrt((gps_x - last_gps[0])**2 + (gps_y - last_gps[1])**2)
		last_gps = (gps_x, gps_y, gps_t)	

	last_gps_index = gps_index
	last_point = (x,y,t)

if last_gps[2] < t:	
	gps_dist += sqrt((x - last_gps[0])**2 + (y - last_gps[1])**2)

print(100*(real_dist - gps_dist)/real_dist)

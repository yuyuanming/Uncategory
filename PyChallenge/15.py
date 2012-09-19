import datetime

for year in range(1996, 1582, -20):
	if datetime.date(year, 1, 1).weekday() == 3:
		print year,

# second youngest suggests year 1756
# January 27 reveals it is "Mozart" by wikipedia
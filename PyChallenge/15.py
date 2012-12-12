import calendar

for year in range(1996, 1582, -20):
	if calendar.weekday(year, 1, 1) == 3:
		print year,

# second youngest suggests year 1756
# January 27 reveals it is "Mozart" by wikipedia
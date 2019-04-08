def max_time(jobs):
	length = len(jobs)
	for i in range(length):
		for j in range(length - 1 - i):
			if jobs[j][1] > jobs[j+1][1]:
				max = jobs[j][1]
			else:
				max = jobs[j+1][1]
	return max
def sort(jobs):
	n = len(jobs)
	for i in range(n):
		for j in range(n - i - 1):
			if jobs[j][2] < jobs[j+1][2]:
				jobs[j],jobs[j+1] = jobs[j+1],jobs[j]
	print(jobs)
def job_scheduling(jobs,max_limit):
	new_jobs = [0] * max_limit
	print(new_jobs)
	profit = 0
	for i in range(max_limit):
		if (i+1) <= jobs[i][1]:
			new_jobs[i] = jobs[i][1]
			profit += jobs[i][2]
	print(new_jobs)
	print(profit)
def main():
	jobs = [['1',9,14],
	['2',2,4],
	['3',5,18],
	['4',7,1],
	['5',4,25],
	['6',2,20],
	['7',5,8],
	['8',7,10],
	['9',4,12],
	['10',3,5],
	]
	max_limit = max_time(jobs)
	sort(jobs)
	job_scheduling(jobs,max_limit)



if __name__ == '__main__':
	main()



import random

#Function to output array of 20 random numbers
def spit():
    test_array = []
    for i in range(20):
        test_array.append(random.randint(0, 100))
    print("Sample array:\t\t", test_array)
    return test_array

#Function to sort array in descending order using the radix algorithm
def radix_sort(arr):
    maximum = max(arr)
    exp = 1

    while maximum// exp > 0:
        mega = [[] for _ in range(10)]

        for num in arr:
            digit = (num // exp) % 10
            mega[digit].append(num)
            
        arr = []
        for mini in mega:
            for num in mini:
                arr.append(num)
        exp *=10
        
    print("After descending radix sort:\t", arr[::-1])
    return arr

#Function to sort array in ascending order using the bubble sort algorithm
def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    print("After ascending bubble sort:\t", arr)
    return arr

#Function to search for user input in array using binary search algorithm
def binary_search(arr, x):
    start = 0
    end = len(arr) - 1
    
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == x:
            print(x, "is in array")
            return True 
        elif arr[mid] > x:
            end = mid - 1
            mid = (start + end) // 2
        else:
            start = mid + 1
            mid = (start + end) // 2
    print("After Binary search:", x, "is not in array")
    return False

#Test
sample = spit()
radix_sort(sample)
bubble_sort(sample)
binary_search(sample, 34)




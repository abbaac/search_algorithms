#Function to output array of 20 random numbers
def spit()
  Array.new(20) { rand(0..100) }
end

#Function to sort array in descending order using the radix algorithm
def radix_sort(arr)
    max_value = arr.max
    num_digits = Math.log10(max_value).to_i + 1
  
    num_digits.times do |digit|
      buckets = Array.new(10) { [] }
  
      arr.each do |num|
        index = (num / (10 ** digit)) % 10
        buckets[index] << num
      end
  
      arr = buckets.flatten
    end
    arr = arr.reverse
    puts "After descending radix sort: [#{arr.join(',')}]"
end

#Function to sort array in ascending order using the bubble sort algorithm
def bubble_sort(arr)
  len = arr.length
  (len-1).times do |i|
    (0...len-i-1).each do |j|
      if arr[j] > arr[j + 1]
        arr[j], arr[j + 1] = arr[j + 1], arr[j]
      end
    end
  end
  puts "After ascending bubble sort: [#{arr.join(',')}]"
  arr
end

#Function to search for user input in array using binary search algorithm
def binary_search(arr, target)
  low = 0
  high = arr.length - 1

  while low <= high
    mid = (low + high) / 2
    if arr[mid] == target
      puts "After Binary search: Target found at index #{mid}"
      return mid # Target found, return the index
    elsif arr[mid] < target
      low = mid + 1 # Target is in the right half
    else
      high = mid - 1 # Target is in the left half
    end
  end
  puts "After Binary search: Target not found"
  return -1 # Target not found
end

#Test
sample = spit()
puts "Sample array is:\t\t[#{sample.join(',')}]"
radix_sort(sample)
bubble_sort(sample)
puts "Enter a number to search: "
target = number = gets.chomp.to_i
binary_search(sample, target)
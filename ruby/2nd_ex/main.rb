def err(exc)
  raise StandardError.new(exc)
end

def init
  val = gets.to_i
  err("Invalid input") if val <= 0
  val
end

def cmp(arr, v)
  err("The volume of the watering can is not enough to water the flower") if v < arr.max
end

def counting_steps(arr, v)
  count = 0
  tmp = v

  arr.each_with_index do |value, i|
    if tmp < value
      tmp = v
      count += i * 2
    end
    count += 1
    tmp -= value
  end

  count
end

n = init

arr = []
n.times do
  arr << init
end

v = init

cmp(arr, v)

puts counting_steps(arr, v)

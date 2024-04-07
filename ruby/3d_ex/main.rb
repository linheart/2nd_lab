def err(exc)
  raise StandardError, exc
end

def init
  gets.to_i
end

def counting_dup(n)
  a = b = init
  count = 0

  (n - 1).times do
    a = init
    count += 1 if a == b
    b = a
  end
  count
end

n = init
err("Invalid input") if n <= 0

puts counting_dup(n)

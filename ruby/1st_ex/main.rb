def err(exc)
  raise Exception.new(exc)
end

def init
  val = gets.to_i
  if val <= 0
    err("Invalid input")
  end
  val
end

def func(s, n, m)
  if s * m > (s - s / 7) * n
    return -1
  end
  return (s * m / n.to_f).ceil
end

s = init()
n = init()
m = init()

puts func(s, n, m)

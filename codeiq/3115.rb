while g = gets
  l = g.chomp.split('').sort.map(&:to_i)
  puts l[0].zero? ? l[1] : l[3]
end

max, progress, char = gets.chomp.split(',')
puts (max.to_f >= progress.to_f ? char * (progress.to_f / max.to_f * 100).floor : 'invalid')

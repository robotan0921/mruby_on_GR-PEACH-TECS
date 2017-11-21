
begin
	i = 0
    loop do
        puts "Hello, world! [#{i}]"
        i += 1
        LED.off
        RTOS.delay(1000000)
        LED.color = :red
        RTOS.delay(1000000)
        LED.off
        RTOS.delay(1000000)
        LED.color = :green
        RTOS.delay(1000000)
        LED.off
        RTOS.delay(1000000)
        LED.color = :blue
        RTOS.delay(1000000)
    end
rescue => e
    puts e
end

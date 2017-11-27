begin
    loop do
        LED.color = :red
        RTOS.delay(1000)
        LED.color = :green
        RTOS.delay(1000)
        LED.color = :blue
        RTOS.delay(1000)
    end
rescue => e
    puts e
end
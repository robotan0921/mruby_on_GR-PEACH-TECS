begin
    loop do
    	if Button.pressed?
        	LED.color = :red
       	else
	        LED.color = :blue
	    end
    end
rescue => e
    puts e
end
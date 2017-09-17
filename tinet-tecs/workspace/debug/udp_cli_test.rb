require 'socket'

u1 = UDPSocket.new()
u1.connect('192.168.1.200', 8931)

u2 = UDPSocket.new()
u2.bind('192.168.1.56', 50000)


loop do
    sleep 1
    begin
        puts "[Client] >>"
        u1.send("Hello, world!", 0)
    rescue
        puts "[Client] Error send"
    end
    begin
        p u2.recvfrom_nonblock(1024)
    rescue => e_var
        puts "[Client] Error, recvfrom"
        # puts "#{e_var}"
    end
end

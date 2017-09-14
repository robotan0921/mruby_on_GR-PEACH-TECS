require 'socket'

u1 = UDPSocket.new()
u1.bind('192.168.1.56', 8931)

u2 = UDPSocket.new()
u2.connect('192.168.1.56', 50000)


loop do
    sleep 1
    begin
        puts "[Client] >>"
        u2.send("Hello, world!", 0)
    rescue
        puts "[Client] Error send"
    end

    begin
        p u1.recvfrom_nonblock(8931)
    rescue
        puts "[Client] Error, recvfrom"
    end
end

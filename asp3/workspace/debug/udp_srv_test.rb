require 'socket'

u1 = UDPSocket.new()
u1.bind('192.168.1.56', 8931)

loop do
    sleep 1
    begin
        p u1.recvfrom_nonblock(8931)
    rescue
        puts "[Client] Error, recvfrom"
    end
end

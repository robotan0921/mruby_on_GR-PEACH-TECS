require 'socket'

u = UDPSocket.new()
u.bind('192.168.1.56', 50000)


loop do
    begin
        p u2.recvfrom_nonblock(1024)
    rescue => e_var
        puts "[Client] Error, recvfrom"
        # puts "#{e_var}"
    end
end

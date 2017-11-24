class RTOS < TECS::TsKernel
	private
	def initialize()
	super "BridgeKernel"
	end
	@@instance = self.new

	public
	def self.delay(time)
		@@instance.delay(time)
	end
	def self.msec
		time = TECS::ULongPointer.new(1)
		@@instance.getTime(time)
		time.value
	end
	def self.usec
		time = TECS::ULongPointer.new(1)
		@@instance.getMicroTime(time)
		time.value
	end
	def self.sleep
		@@instance.sleep
	end
	def self.id
		id = TECS::IntPointer.new(1)
		@@instance.getTaskId(id)
		return id.value
	end
end

class TCP < TECS::TsMrubyTCP
	private
		def initialize()
			@myaddr = 0
			@myport = 0
			@dstaddr = 0
			@dstport = 0
			super "BridgeTCP"
		end

	public
		# def make_ipv4_addr
		# 	self.split(".")
		# 	return addr[0]<<24 | addr[1]<<16 | addr[2]<<8 | addr[3]
		# end
		def acpt descid
			ipaddr = TECS::UInt32Pointer.new(1)
			portno = TECS::UInt16Pointer.new(1)
			accept(descid, ipaddr, portno, 100000000)
		end
		# def connect(addr, port)
		def connect(a, b, c, d, port)
			puts ">>connect<<"
			# addr = addr.split(".")
			# puts ">>connect<< --> split #{addr}"
			# @dstaddr = (addr[0].to_i << 24) | (addr[1].to_i << 16) | (addr[2].to_i << 8) | (addr[3].to_i)
			# @dstaddr = make_ipv4_addr(addr[0].to_i, addr[1].to_i, addr[2].to_i, addr[3].to_i)
			@dstaddr = make_ipv4_addr(a, b, c, d)
			puts ">>connect<< --> dstaddr #{@dstaddr.to_s}"
			@dstport = port
			puts ">>connect<< --> port #{@port.to_s}"
		end
		def snd msg
			puts ">>snd<<"
			len = msg.to_s.length + 1
			puts ">>snd<< --> len #{len}"
			msg_buf = TECS::CharPointer.new(len)
			puts ">>snd<< --> msg_buf"
			msg_buf.from_s msg.to_s
			puts ">>snd<< --> msg_buf 2"
			send(msg_buf, len, 10000000)
			puts ">>snd<< --> send"
		end
		def recv
			msg_buf = TECS::CharPointer.new(32)
			receive(msg_buf, 32, 10000000)
			# msg_buf[].each{|i|
			# 	puts i
			# }
			# for i in 0..10 do
			# 	puts msg_buf[i].value
			# end
			puts "msg_buf size = #{msg_buf.size}"
			puts "msg_buf value = #{msg_buf.value}"
			puts "msg_buf to_s = #{msg_buf.to_s}"
			return msg_buf.to_s 	# msg_buf[0].value
		end
end

begin
	puts "[mruby]:tcp_sample [TaskID:#{RTOS.id}]"

	cep = TCP.new()
	cep.acpt 0

	loop do
		puts "[[TCP sample]]"
		RTOS.delay(1000000)
		cep.snd "Hello, world!"
		# RTOS.delay(1000000)
		# cep.recv
	end

	puts "TCP sample application is ended!! [TaskID:#{RTOS.id}]"

rescue => e
	puts "[ERROR]" + e
end
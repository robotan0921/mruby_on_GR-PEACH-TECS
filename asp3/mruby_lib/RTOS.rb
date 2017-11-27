class RTOS < TECS::TsKernel
	private
	def initialize()
		super "BridgeKernel"
	end
	@@instance = self.new

	public
	def self.delay(time)
		@@instance.delay(1000*time)
	end
	def self.msec
		time = TECS::ULongPointer.new(1)
		@@instance.getTime(time)
		time.value
	end
	def self.usec
		time = TECS::ULongPointer.new(1)
		@@instance.getMicroTime(time)
		(time.value)/1000
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

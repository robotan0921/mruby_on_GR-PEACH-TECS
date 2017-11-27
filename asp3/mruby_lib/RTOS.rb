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
		time = TECS::UInt64Pointer.new(1)
		@@instance.getTime(time)
		(time.value)/1000
	end
	def self.usec
		return @@instance.fetchHighResolutionTimer
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

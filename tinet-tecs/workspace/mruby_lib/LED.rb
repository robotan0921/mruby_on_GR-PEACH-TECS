class LED < TECS::TsLED
	@@color_hash = {:user=>12, :red=>13, :green=>14, :blue=>15}
	private
	def initialize()
		super "BridgeLED"
	end
	@@instance = self.new

	public
	def self.color= (clr)
		@@instance.off
		@@instance.setColor( @@color_hash[clr] )
	end
	def self.off
		@@instance.off
	end
end
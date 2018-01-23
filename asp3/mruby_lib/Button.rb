class Button < TECS::TsButton
	private
	def initialize()
		super "BridgeButton"
	end
	@@instance = self.new

	public
	def self.pressed?
		@@instance.isPressed
	end
end
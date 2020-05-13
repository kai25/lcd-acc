class LCDDisplay
{
	private:
		bool isBacklightEnabled;
	
	public:
		LCDDisplay();
		void init();
		void enableBacklight();
		void disableBacklight();
		void toggleBacklight();
		void clearDisplay();
		void setLineText(char* text, int line);
		void printCoordinate(char* text, double coord, int lint);
	  void printInt(char* text, int val, int lint);
};

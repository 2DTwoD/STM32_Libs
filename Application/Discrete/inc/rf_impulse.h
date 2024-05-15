#ifndef RF_IMPULSE_H
#define RF_IMPULSE_H

enum IMPULSE {
	RISE = 0,
	FALL
};

class RFimpulse{
	private:
		bool prev;
		bool out;
		IMPULSE dir;
	public:
		RFimpulse(IMPULSE dir);
		void set(bool value);
		bool get();
		RFimpulse& operator=(bool value);
};
#endif //RF_IMPULSE_H
struct timer{
	clock_t _START;
	timer(){_START = clock();}
	double time(){return (clock()-_START)/double(CLOCKS_PER_SEC);}
};

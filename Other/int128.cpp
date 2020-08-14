typedef __int128 i128;
string to_string(i128 num) {
	ll digs, tenPow18 = 1e18;
	string str, digS, lead;
	do {
		digs = num % tenPow18;
		digS = to_string(digs); 
		lead = (digs != num) ? string(18 - digS.length(), '0') : "";
		str = lead + digS + str;
		num = (num - digs) / tenPow18;
	} while (num != 0);
	return str;
}

int analiz(int d, float s) {
	if(d <= 30) {
		if (s <= 100000) s -= s / 10;
			else s -= s / 10;
	}
		else if (d > 30 && d <= 120) {
			if (s <= 100000) s += s * 0.02;
				else s += s * 0.03;
		}
			else if (d > 120 && d <= 240) {
				if (s <= 100000) s += s * 0.06;
					else s += s * 0.08;
			}
				else if (d > 240 && d <= 365) {
						if (s <= 100000) s += s * 0.12;
							else s += s * 0.15;
				}
	return 0;
}

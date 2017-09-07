class Solution {
public:
	int flipLights(int n, int m) {
		switch (n)
		{
		case 0:
			return 0;
		case 1:
			return 1 + (m >= 1);
		case 2:
			if (m & 1)
				return (m >= 3) ? 4 : 3;
			else
				return (m >= 2) ? 4 : 1;
		default: // larger or equal to 3.
			if (m & 1)
				return (m >= 3) ? 8 : 4;
			else
				return (m >= 4) ? 8 : (m >= 2) ? 7 : 1;
		}
	}
};
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::endl;

class Solution {
public:
	string convert(string s, int numRows) {
		const int len = s.length();
		char* buf = (char *)malloc((len + 1) * sizeof(char));
		const char* input = s.c_str();

		const int loop_step = numRows > 2 ? (numRows << 1) - 2 : numRows;
		const int num_loops = len / loop_step;
		const int last_loop_size = len - loop_step * num_loops;

		int loop_offset = 0;		//Offset in a loop
		int loop_jump_offset = 0;	//Offset to jump in one loop for middle rows. For the first and last row, it is zero.
		int loop_idx = 0;			//Loop index
		int input_offset = 0;		//Offset in the whole input array
		int output_offset = 0;		//Offset in the whole output array
		for (output_offset = 0; output_offset < len; ++output_offset) {
			//Check whether has reached the end of this row
			if (loop_idx > num_loops || (loop_idx == num_loops && loop_offset >= last_loop_size)) {
				//Reached the end of this row.
				//Jump to the next row.
				input_offset = ++loop_offset;
				//Clear loop index.
				loop_idx = 0;
				//Calc the offset to jump
				loop_jump_offset = (numRows - loop_offset - 1) << 1;
			}

			//Immediately fill one character.
			buf[output_offset] = input[input_offset];

			//Check if able to jump in the loop
			if (loop_jump_offset) {	//Not the first or last row
				if (loop_idx < num_loops || loop_offset + loop_jump_offset < last_loop_size) {
					//Able to jump in the loop.
					buf[++output_offset] = input[input_offset + loop_jump_offset];
				}
			}

			//Jump to the same start location in the next loop.
			input_offset += loop_step;
			//Increase the loop index.
			++loop_idx;
		}
		buf[len] = '\0';

		string res(buf);
		free(buf);
		return res;
	}
};

int main() {
	Solution solution;

	cout << solution.convert("", 1) << endl;
	cout << solution.convert("ABCD", 2) << endl;
	cout << solution.convert("PAYPALISHIRING", 3) << endl;

	return 0;
}
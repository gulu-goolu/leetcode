class Solution {
public:
    int myAtoi(string s) {
        auto ptr = s.c_str();

        while (*ptr == ' ') ptr++; // 移除前导空格
        // printf("%s\n", ptr);

        int k = 1;
        if (*ptr == '-') {
            k = -1;
            ptr++;
        } else if (*ptr == '+') {
            ptr++;
        }

        int64_t val = 0;
        while (*ptr && *ptr >= '0' && *ptr <= '9') {
            val = val * 10 + (*ptr - '0');
            ptr++;
            // printf("cur: %d, last: %s\n", val, ptr);

            // 阶段
            if (val * k > INT_MAX) {
                return INT_MAX;
            } else if (val * k < INT_MIN) {
                return INT_MIN;
            }
        }

        return k * val;
    }
};

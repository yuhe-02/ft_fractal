double ascii_to_double(const char *str) 
{
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 10.0;
    int is_negative = 0;
    int is_fraction = 0;

    // 先頭に符号があるか確認
    if (*str == '-') {
        is_negative = 1;
        str++;
    } 
    // 文字列を解析して整数部分を取得
    while (*str != '\0') {
        if (*str == '.') {
            is_fraction = 1;
            str++;
            continue;
        }

        if (*str >= '0' && *str <= '9') {
            if (is_fraction) {
                // 小数点以下の部分の処理
                fraction += (*str - '0') / divisor;
                divisor *= 10.0;
            } else {
                // 整数部分の処理
                result = result * 10.0 + (*str - '0');
            }
        } else {
            // 無効な文字があった場合には停止
            break;
        }
        str++;
    }

    // 負数の場合は符号を反転
    if (is_negative) {
        result = -(result + fraction);
    } else {
        result += fraction;
    }

    return result;
}
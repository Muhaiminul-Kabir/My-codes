void convertInt(char str[], long int a) {
    long int i, rem, count = 0, f;
    f = a;
    while (f != 0) {
        count++;
        f /= 10;
    }
    for (i = 0; i < count; i++) {
        rem = a % 10;
        a = a / 10;
        str[count - (i + 1)] = rem + '0';
    }
    str[count] = '\0';
}

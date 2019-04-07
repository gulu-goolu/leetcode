# reverse-words-in-a-string

```cpp
string reverse_words(string s) {
    int off = 0;
    int len = static_cast<int>(s.size());
    while (s[off] == ' ') {
        off++;
    }
    int i = 0;
    while (off < len) {
        if (s[off] == ' ') {
            s[i++] = s[off];
            while (off < len && s[off] == ' ') {
                off++;
            }
        }
        while (off < len && s[off] != ' ') {
            s[i++] = s[off++];
        }
    }
    if (s[i - 1] == ' ') {
        --i;
    }
    s.resize(i);
    len = i;

    for (i = 0; i < len / 2; ++i) {
        std::swap(s[i], s[len - 1 - i]);
    }

    off = 0;
    while (off < len) {
        const int _off = off;
        while (off < len && s[off] != ' ') {
            ++off;
        }

        char *ptr = &s[_off];
        const int count = off - _off;
        for (int i = 0; i < count / 2; ++i) {
            std::swap(ptr[i], ptr[count - 1 - i]);
        }

        off++;
    }

    return s;
}
```
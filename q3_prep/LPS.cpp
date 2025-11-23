void buildLPS(string &p, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < p.length()) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1]; abcabd 0 0 0 1 2 0 
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
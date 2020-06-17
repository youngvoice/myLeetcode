/**
 * algorithm --> string
 * traversal
 * */
 /*
bool isAnagram(char * s, char * t){
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; t[j] != '\0'; j++) {
            if (s[i] == t[j]) { // set non letter, ascii
                s[i] = '\n';
                t[j] = '\n';
                break;
            }
                
        }
        if (t[j] == '\0') {
            printf("here1 j=%d i=%d\n", j,i);
            return false;
        }
            
    }
    for (j = 0; t[j] != '\0'; j++)
        if (t[j] != '\n') {
            printf("here2\n");
            return false;
        }
            
    return true;

}
*/

/**
 * letter frequency histogram
 * */
#define LETTER_NUM 26
bool isAnagram(char * s, char * t){

    int freq_hist_s[LETTER_NUM];
    int freq_hist_t[LETTER_NUM];
    int i;
    for (i = 0; i < LETTER_NUM; i++) {
        freq_hist_s[i] = 0;
        freq_hist_t[i] = 0;
    }
    
    while (*s != '\0') {
        freq_hist_s[(*s-'a')]++;
        s++;
    } 
    while (*t != '\0') {
        freq_hist_t[(*t-'a')]++;
        t++;
    }
    for (i = 0; i < LETTER_NUM; i++) {
        if (freq_hist_s[i] != freq_hist_t[i])
            return false;
    }
    return true;

}
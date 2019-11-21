//
// Created by Илья on 21.11.2019.
//

/**
 *
 * function returns a pointer to the next token in the string addressed by the @param str.
 * The characters from the string @param sep are the separators that define the token.
 * If there is no token to be returned, a null pointer is returned.
 * @param str string to be modified
 * @param sep string of separators
 * @param prev_ptr uses for continuation splitting string
 * @return begin pointer to the beginning of token
 *
 */
char* my_strtok(char* str, const char*sep) {

    static char* prev_ptr = NULL;

    if (str)
        prev_ptr = str; //if new string splitting

    if (prev_ptr == NULL)
        return NULL; //in case of inaccurate use

    if (*prev_ptr == '\0')
        return NULL; // in case of string end

    skipSeps(&prev_ptr, sep);
    char* begin = prev_ptr;
    skipNonSeps(&prev_ptr, sep);

    if (*prev_ptr != '\0') {

        *prev_ptr = '\0'; //completion string
        prev_ptr++;

    }

    return begin;

}
/**
 *
 * @param[in] **str pointer to char array will be modified
 * @param[in] *sep char array with characters should be skipped
 * function replace beginning of char array
 * until it reaches character NOT IN @param sep
 *
 */
void skipSeps(char** str, const char* sep) {

    while (in(**str, sep))
        (*str)++;

}

/**
 *
 * @param[in] **str pointer to char array will be modified
 * @param[in] *sep  char array with characters shouldn't be skipped
 * function replace beginning of char array
 * until it reaches character IN @param sep
 *
 */
void skipNonSeps(char** str, const char* sep) {

    while (in(**str, sep) == 0 && **str != '\0')
        (*str)++;

}

/**
 *
 * @param ch
 * @param str
 * @return 1 if str includes ch, 0 otherwise
 *
 */
int in(char ch, char* str) {

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ch)
            return 1;

    return 0;

}

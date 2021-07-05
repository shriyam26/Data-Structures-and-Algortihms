int firstNonRepeating(char* str)
{
    pair<int, int> arr[NO_OF_CHARS];
 
    for (int i = 0; str[i]; i++) {
        (arr[str[i]].first)++;
        arr[str[i]].second = i;
    }
 
    int res = INT_MAX;
    for (int i = 0; i < NO_OF_CHARS; i++)
 
        // If this character occurs only
        // once and appears before the
        // current result, then update the
        // result
        if (arr[i].first == 1)
            res = min(res, arr[i].second);
 
    return res;
}

char nonrepeatingCharacter(string S)
    {
        int us[26] = {0};
        int len = S.length();
        for(int i = 0; i <len; i++){
            us[S[i]- 'a']++;
        }
        for(int i = 0; i < len; i++){
            if(us[S[i] - 'a'] == 1){
                return S[i];
            }
        }
        return '$';
    }
}
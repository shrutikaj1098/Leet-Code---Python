class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if((s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') && (s[j]>='a' && s[j]<='z' || s[j]>='A' && s[j]<='Z'))
            {
                swap(s[i],s[j]);
                i++;j--;
            }
            else if((s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') && !(s[j]>='a' && s[j]<='z' || s[j]>='A' && s[j]<='Z'))
            {
                j--;
            }
            else if(!(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') && (s[j]>='a' && s[j]<='z' || s[j]>='A' && s[j]<='Z'))
            {
                i++;
            }
            else
            {
                i++;j--;
            }
        }
        return s;
    }
};
 class Solution {
    public String longestPalindrome(String s) {
        if (s.length() <= 1) {
            return s;
        }
        
        String longest = "";
        
        for (int i = 0; i < s.length(); i++) {
            
            String p1 = expandAroundCenter(s, i, i);
            if (p1.length() > longest.length()) {
                longest = p1;
            }
            
            
            String p2 = expandAroundCenter(s, i, i + 1);
            if (p2.length() > longest.length()) {
                longest = p2;
            }
        }
        
        return longest;
    }
    
    private String expandAroundCenter(String s, int low, int high) {
        while (low >= 0 && high < s.length() && s.charAt(low) == s.charAt(high)) {
            low--;
            high++;
        }
    
        if (low + 1 <= high && low + 1 < s.length() && high <= s.length()) {
            return s.substring(low + 1, high);
        }
        return "";
    }
}

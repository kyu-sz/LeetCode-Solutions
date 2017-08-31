import java.util.ArrayList;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.List;

class Solution {
    private String reverse(String str) {
        StringBuilder sb = new StringBuilder(str.length());
        for (int i = str.length() - 1; i >= 0; --i) {
            sb.append(str.charAt(i));
        }
        return sb.toString();
    }

    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> ans = new ArrayList<>();

        HashMap<String, Integer> originalWords = new HashMap<>();
        HashMap<String, Integer> reversedWords = new HashMap<>();
        Integer emptyStringIndex = null;
        for (int i = 0; i < words.length; ++i) {
            String word = words[i];
            if (word.length() == 0) {
                emptyStringIndex = i;
            } else {
                originalWords.put(word, i);
                reversedWords.put(reverse(word), i);
            }
        }

        for (int i = 0; i < words.length; ++i) {
            String word = words[i];
            if (word.length() > 0) {
                if (emptyStringIndex != null) {
                    // Check if the word itself is a palindrome.
                    int radius = word.length() >> 1;
                    boolean isPalindrome = true;
                    for (int j = 0; j < radius; ++j) {
                        if (word.charAt(j) != word.charAt(word.length() - 1 - j)) {
                            isPalindrome = false;
                            break;
                        }
                    }
                    if (isPalindrome) {
                        ArrayList<Integer> pair = new ArrayList<>(2);
                        pair.add(i);
                        pair.add(emptyStringIndex);
                        ans.add(pair);

                        pair = new ArrayList<>(2);
                        pair.add(emptyStringIndex);
                        pair.add(i);
                        ans.add(pair);
                    }
                }

                Integer revWordID = reversedWords.get(word);
                if (revWordID != null && revWordID != i) {
                    ArrayList<Integer> pair = new ArrayList<>(2);
                    pair.add(i);
                    pair.add(revWordID);
                    ans.add(pair);
                }
                for (int j = 0; j < word.length(); ++j) {
                    int radius = j >> 1;

                    // Find palindromes from the start.
                    boolean isPalindrome = true;
                    for (int r = 0; r <= radius; ++r) {
                        if (word.charAt(r) != word.charAt(j - r)) {
                            isPalindrome = false;
                            break;
                        }
                    }
                    if (isPalindrome) {
                        String reversedResidual = reverse(word.substring(j + 1));
                        Integer id = originalWords.get(reversedResidual);
                        if (id != null) {
                            List<Integer> pair = new ArrayList<>(2);
                            pair.add(id);
                            pair.add(i);
                            ans.add(pair);
                        }
                    }

                    // Find palindromes from the tail.
                    isPalindrome = true;
                    for (int r = 0; r <= radius; ++r) {
                        if (word.charAt(word.length() - 1 - r) != word.charAt(word.length() - 1 - j + r)) {
                            isPalindrome = false;
                            break;
                        }
                    }
                    if (isPalindrome) {
                        String residual = word.substring(0, word.length() - 1 - j);
                        Integer id = reversedWords.get(residual);
                        if (id != null) {
                            List<Integer> pair = new ArrayList<>(2);
                            pair.add(i);
                            pair.add(id);
                            ans.add(pair);
                        }
                    }
                }
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        List<List<Integer>> ans;

        ans = solution.palindromePairs(new String[]{"a", "b", "c", "ab", "ac", "aa"});
        for (List<Integer> pair : ans) {
            System.out.println("[" + pair.get(0) + ", " + pair.get(1) + "]");
        }
        System.out.println();

        ans = solution.palindromePairs(new String[]{"a", "abc", "aba", ""});
        for (List<Integer> pair : ans) {
            System.out.println("[" + pair.get(0) + ", " + pair.get(1) + "]");
        }
        System.out.println();

        ans = solution.palindromePairs(new String[]{"abcd", "dcba", "lls", "s", "sssll"});
        for (List<Integer> pair : ans) {
            System.out.println("[" + pair.get(0) + ", " + pair.get(1) + "]");
        }
        System.out.println();
    }
}
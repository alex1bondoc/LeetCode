class Solution {
    private static final Map<Character, String> MAP = Map.of(
        '2', "abc", '3', "def", '4', "ghi", '5', "jkl",
        '6', "mno", '7', "pqrs", '8', "tuv", '9', "wxyz"
    );
    private List<String> res = new ArrayList<>();

    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) return res;
        back(0, digits, new StringBuilder());
        return res;
    }

    private void back(int i, String digits, StringBuilder cur) {
        if (i == digits.length()) {
            res.add(cur.toString());
            return;
        }
        for (char c : MAP.get(digits.charAt(i)).toCharArray()) {
            cur.append(c);
            back(i + 1, digits, cur);
            cur.deleteCharAt(cur.length() - 1);   // undo
        }
    }
}
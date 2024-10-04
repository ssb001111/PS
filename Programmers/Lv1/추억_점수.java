import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        
        HashMap<String, Integer> h = new HashMap<>();
        
        for (int i = 0; i < name.length; i++){
            h.put(name[i], yearning[i]);
        }
        
        for (int i = 0; i < photo.length; i++){
            String[] s = photo[i];
            int score = 0;
            for (int j = 0; j < s.length; j++){
                String t = s[j];
                if (h.containsKey(t)){
                    score += h.get(t);
                }
            }
            answer[i] = score;
        }
        return answer;
    }
}

class Solution {
    public int[] solution(String[] park, String[] routes) {
        int sx = 0;
        int sy = 0;
        
        char [][] arr = new char[park.length][park[0].length()];
        
        for (int i = 0; i < park.length; i++){
            arr[i] = park[i].toCharArray();
            if (park[i].contains("S")){
                sy = i;
                sx = park[i].indexOf("S");
            }
        }
        
        for (String s : routes){
            String direction = s.split(" ")[0];
            int length = Integer.parseInt(s.split(" ")[1]);
            
            int nx = sx;
            int ny = sy;
            
            for (int i = 0; i < length; i++){
                
                if (direction.equals("E")){
                    nx++;
                }
                else if (direction.equals("W")){
                    nx--;
                }
                else if (direction.equals("S")){
                    ny++;
                }
                else if (direction.equals("N")){
                    ny--;
                }
                
                if (nx >=0 && ny >=0 && nx < arr[0].length && ny < arr.length){
                    if (arr[ny][nx] == 'X'){
                        break;
                    }
                    else{
                        if (i == (length-1)){
                            sx = nx;
                            sy = ny;
                        }
                    }
                }
            }
        }
        
        int[] answer = {sy, sx};
        return answer;
    }
}

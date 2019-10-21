import java.util.*;

class Main {

    private static Scanner in;
    public static void main(String[] args) {
        in = new Scanner(System.in);

        //solving backjoon 4889
        Stack<Character> s = new Stack<>();
        String data = in.nextLine();
        while(!data.startsWith("-")) {
            data = in.nextLine();
        }

        for(char loop : data.toCharArray()) {
            switch(loop) {
                case '{' :

                    break;

                case '}' :
                    break;

                default :
                    break;
            }
        }
    }
}
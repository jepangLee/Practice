import java.util.*;

class Problem {
    void backjoon_9375 () {
        Scanner in = new Scanner(System.in);

        int inCase = in.nextInt();
        for (int i = 0; i < inCase; i++) {
            int eachCase = in.nextInt();
			HashMap<String, Integer> map = new HashMap<>();

			for (int j = 0; j < eachCase; j++) {
				in.next();
                String data = in.next();
                if (map.containsKey(data)) {
                	int tmp = map.get(data);
                    map.put(data, tmp + 1);
                } else {
                    map.put(data, 1);
                }
            }

            int result = 1;
            for (int loop : map.values()) {
                result *= loop + 1;
            }

            System.out.println(result - 1);
        }
    }
}
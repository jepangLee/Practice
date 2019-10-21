class Problems {
    void DAPC_1 () {
        int in;
        std::cin >> in;

        if (in % 4 == 0 && in % 100 != 0) std::cout << "1";
        else if (in % 400 == 0)      	  std::cout << "1";
        else                	          std::cout << "0";
    }
    void DAPC_2 () {
        int in;
        std::cin >> in;
        
        in %= 10;
        switch (in) {
            case 0:
            case 9:
                std::cout << '1';
                break;
            case 1:
            case 8:
                std::cout << '2';
                break;
            case 2:
            case 7:
                std::cout << '3';
                break;
            case 3:
            case 6:
                std::cout << '4';
                break;
            default:
                std::cout << '5';
                break;
        }
    }
    void backjoon_9375 () {
        int inCase;
        std::cin >> inCase;

        for (int i = 0; i < inCase; i++) {
            int eachCase;
            std::cin >> eachCase;

            std::map<std::string, int> data;

            for (int j = 0; j < eachCase; j++) {
                std::string str;
                std::cin >> str >> str;
                if (data.find(str) == data.end() ) {
                    data.insert(make_pair(str, 1));
                } else {
                    int tmp = data[str];
                    data.insert(make_pair(str, tmp));
                }
            }
            int result = 1;

            for (std::pair<std::string, int> tmp : data) {
                result *= tmp.second + 1;
            }

            std::cout << result - 1;
        }
    }
}
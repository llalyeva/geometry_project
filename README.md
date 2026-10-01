 ✗ clang++ main.cpp gift_wrapping.cpp -std=c++17 \                       
-I$(brew --prefix sfml)/include \
-L$(brew --prefix sfml)/lib \
-lsfml-graphics \
-lsfml-window \
-lsfml-system \
-o app
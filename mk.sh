#-fsanitize=address -g \
reset
file="main"
gcc \
main/$file.c debug/*.c mlx/*.c lib/*.c src/init/*.c src/mlx/*.c src/solve/*.c actor/*.c \
-I inc \
-L /usr/include/lib -I /usr/include \
-lXext -lX11 -lm -lbsd -lXrandr
# So_long
Create 2D game using MinilibX graphics library understanding what is minilibx library, flood fill algorithm.<br>
Run “make”, After getting program, pass mapfile as argument.<br>
+A valid map structure must include 1 Player, at least 1 Exit, at least 1 Collectible.<br>
Must be rectangular, must be surrounded by wall(1), must has .ber extension.<br>
No other characters than “PEC10”. The player can only be moved by “WASD”.<br>

# Steps what I did
1. Get mapfile height (also width) so that we can allocate map info to 2D array using "get_next_line"
2. Check if this 2D array is valid, rectangular? valid character? all objects is in walkable area?
3. It's time to use Minilibx! Initialize mlx, pop up window.
4. Set .xpm file to image pointer using "mlx_xpm_file_to_image" from mlx. Then loop through 2D array and set each object using "mlx_put_image_to_window"
5. It's time to do key handle! I used mlx_hook() twice. One is for when key is pressed, call key_hook function. The other one is for when you click cross button, call close_window.
6. In key_hook(), hold current player position as well as update its position every time key is pressed. Using this 2 position (current and next), re-assign value of 2D array, next would be 'P' and current would be '0' then display image again. But before we move player, must check if what is next object? ex: if it is '0', we can move but what if '1'?
7. In close_window, don't forget free !

# Flood fill alorithm
To check if all objects is in walkable are, I used flood fill algorithm. Inside is_valid_path.c file, there is function called "mark()" is given player position to check if player can move, can collect coin, and exit that area is going to be marked "M". As you can see, I called this function again "mark_again()", which can cover case if coin is behind "E" and blocked. (see below)<br>
11111<br>
10011<br>
1PEC1<br>
11111<br>
This way worked, but I think it's not really efficient as I copied map, called mark function and freed map twice. I am sure there is better way to cover this case so please share your thoughts.

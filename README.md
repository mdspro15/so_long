# so_long
Create 2D game using MinilibX graphics library understanding what is minilibx library, flood fill algorithm
Run “make”, After getting program, pass mapfile as argument.
A valid map structure must include 1 Player, at least 1 Exit, at least 1 Collectible.
Must be rectangular, must be surrounded by wall(1), must has .ber extension.
No other characters than “PEC10”. The player can only be moved by “WASD”

# step
1. Get mapfile height (also width) so that we can allocate map info to 2D array using "get_next_line"
2. Check if this 2D array is valid, rectangular? valid character? all objects is in walkable area?
3. It's time to use Minilibx! Initialize mlx, pop up window.
4. Set .xpm file to image pointer using "mlx_xpm_file_to_image" from mlx. Then loop through 2D array and set each object using "mlx_put_image_to_window"
5. It's time to do key handle! I used mlx_hook() twice. One is for when key is pressed, call key_hook function. The other one is for when you click cross button, call close_window.

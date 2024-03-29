# So_long
2D game in C
--------------
Create a 2D game in C using the following rules:
(source en.subject.pdf - so long - 42school/ codam)
## Game
• The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.\
• The W, A, S, and D keys must be used to move the main character.\
• The player should be able to move in these 4 directions: up, down, left, right.\
• The player should not be able to move into walls.\
• At every move, the current number of movements must be displayed in the shell. \
• You have to use a 2D view (top-down or profile).\
• The game doesn’t have to be real time.\
• Although the given examples show a dolphin theme, you can create the world you want.

## Graphic management
• Your program has to display the image in a window.\
• The management of your window must remain smooth (changing to another win-
  dow, minimizing, and so forth).\
• Pressing ESC must close the window and quit the program in a clean way.\
• Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.\
• The use of the images of the MiniLibX is mandatory.

## Map
• The map has to be constructed with 3 components: walls, collectibles, and free
  space.\
• The map can be composed of only these 5 characters
<ul>
  <li>0 for an empty space,</li>
  <li>1 for a wall,</li>
  <li>C for a collectible,</li>
  <li>E for a map exit, </li>
  <li>P for the player’s starting position.</li>
</ul>
• The map must contain at least 1 exit, 1 collectible, and 1 starting position.<br/>
• The map must be rectangular.<br/>
• The map must be closed/surrounded by walls. If it’s not, the program must return an error.<br/>
• You don’t have to check if there’s a valid path in the map.<br/>
• You must be able to parse any kind of map, as long as it respects the above rules.<br/>
• If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error      
  message of your choice.

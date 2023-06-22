# hexdump
## Goal
<strong>Recreate the hexdump function (42 school)</strong>
<br><br>Hexdump is a pool project from the 42 school witch aims to recreate the hexdump command.<br>
For that, I have to deal with the 42's norme and a small list of functions: <br>
* **close**<br>
* **open**<br>
* **read**<br>
* **write**<br>
* **malloc**<br>
* **free**<br>
* **strerror**<br>
* **basename**<br><br>
And I choosed to add **access** to check the accessibility of the file<br>
### function
Hexdump read all bytes of the file(s) and displays it in hexadecimal form. The first element is the address of the first byte of the line (in hexadecimal), it's follow by the 16 typeface write in hexadecimal (again...)<br><br>
The **-C** flag show the ascii value or . if it is'n printable after the line<br>
#### Compilation
* `make`
* `./hexdump [flag] [file1] [file2] ... [fileN]`

### Normal mode
<img src="./.picture/normal_mode.jpg" alt="Alt text" title="normal_mode">

### -C mode
<img src="./.picture/C_mode.jpg" alt="Alt text" title="normal_mode">
<br>Date: jun 3 2022

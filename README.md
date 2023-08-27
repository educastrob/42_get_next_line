<div align = center>

## get_next_line
  
</div>

<p>
  <b>get_next_line</b> is a function that reads a line from a file descriptor. It allows you to retrieve the next line from a file, one line at a time, without having to read the entire file at once. The function is designed to be memory efficient and to work seamlessly with multiple file descriptors.
</p>

## The Project

<h3>Mandatory</h3>
<p>Write a function that will read a line at a time from a file opened.</p>
<table>
<thead>
  <tr>
    <th>File</th>
    <th>Description</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td><a href="https://github.com/educastrob/get_next_line/blob/main/get_next_line.c" target="_blank" rel="noopener noreferrer">get_next_line.c</a></td>
    <td>Function where the file is read and the current line is separeted and returned.</td>
  </tr>
  <tr>
    <td><a href="https://github.com/educastrob/get_next_line/blob/main/get_next_line_utils.c" target="_blank" rel="noopener noreferrer">get_next_line_utils.c</a></td>
    <td>Helper functions from libft.</td>
  </tr>
  <tr>
    <td><a href="https://github.com/educastrob/get_next_line/blob/main/get_next_line.h" target="_blank" rel="noopener noreferrer">get_next_line.h</a></td>
    <td>Header file.</td>
  </tr>
</tbody>
</table>
<h3>Bonus</h3>
<p>Write a function that will read a line at a time from 'n' files opened at the same time.</p>
<table>
<thead>
  <tr>
    <th>File</th>
    <th>Description</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td><a href="https://github.com/educastrob/get_next_line/blob/main/get_next_line_bous.c" target="_blank" rel="noopener noreferrer">get_next_line_bous.c</a></td>
    <td>Function where the file is read and the current line is separeted and returned.</td>
  </tr>
  <tr>
    <td><a href="https://github.com/educastrob/get_next_line/blob/main/get_next_line_utils_bonus.c" target="_blank" rel="noopener noreferrer">get_next_line_utils_bonus.c</a></td>
    <td>Helper functions from libft.</td>
  </tr>
  <tr>
    <td><a href="https://github.com/educastrob/get_next_line/blob/main/get_next_line_bonus.h" target="_blank" rel="noopener noreferrer">get_next_line_bonus.h</a></td>
    <td>Header file.</td>
  </tr>
</tbody>
</table>

---

## How to Execute

First, clone this repository and `cd` into it:

```sh
$> git clone https://github.com/educastrob/get_next_line && cd get_next_line
```

When compiling get_next_line or its bonus version, be sure to include the following flags

```sh
$> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xxx <files>.c.
```

Where the xxx can be substituted by the number of bytes read at a time into the buffer for the read function.

" Tab键的宽度
set tabstop=4
"从不备份
set nobackup
"显示行号
set nu
let &termencoding=&encoding
set fileencodings=utf-8,gbk


"""""""""""""""""""""""""""""""""""""""""
"C，C++ 按F5编译运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
        exec "w"
        if &filetype == 'c'
                exec "!g++ % -o %<"
                exec "! ./%<"
        elseif &filetype == 'cpp'
                exec "!g++ % -o %<"
                exec "! ./%<"
        elseif &filetype == 'java'
                exec "!javac %"
                exec "!java %<"
        elseif &filetype == 'sh'
                :!./%
        elseif &filetype == 'py'
                exec "!python %"
                exec "!python %<"
        endif
endfunc
"C,C++的调试
map <F8> :call Rungdb()<CR>
func! Rungdb()
        exec "w"
        exec "!g++ % -g -o %<"
        exec "!gdb ./%<"
endfunc
"""""""""""""""""""""""""""""""""""""""""

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"""""新文件标题
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"新建.c,.h,.sh,.java文件，自动插入文件头 
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"
""定义函数SetTitle，自动插入文件头 
func SetTitle()
        "如果文件类型为.sh文件 
        if &filetype == 'sh'
                call setline(1,"\#########################################################################")
                call append(line("."), "\# File Name: ".expand("%"))
                call append(line(".")+1, "\# Author: zhonghua")
                call append(line(".")+2, "\# mail:   zhonghua-881008@163.com")
                call append(line(".")+3, "\# Created Time: ".strftime("%c"))
                call append(line(".")+4, "\#########################################################################")
                call append(line(".")+5, "\#!/bin/bash")
                call append(line(".")+6, "")
        else
                call setline(1, "/*************************************************************************")
                call append(line("."), "> File Name: ".expand("%"))
                call append(line(".")+1, "> Author: zhonghua")
                call append(line(".")+2, "> Mail:   zhonghua-881008@163.com ")
                call append(line(".")+3, "> Created Time: ".strftime("%c"))
                call append(line(".")+4, "*************************************************************************/")
                call append(line(".")+5, "")
        endif
        if &filetype == 'cpp'
                call append(line(".")+6, "#include <iostream>")
                call append(line(".")+7, "using namespace std;")
                call append(line(".")+8, "")
        endif
        if &filetype == 'c'
                call append(line(".")+6, "#include <stdio.h>")
                call append(line(".")+7, "")
        endif
        "       if &filetype == 'java'
        "               call append(line(".")+6,"public class ".expand("%"))
        "               call append(line(".")+7,"")
        "       endif
        "新建文件后，自动定位到文件末尾
        autocmd BufNewFile * normal G
endfunc
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

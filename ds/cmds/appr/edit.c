// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
  mixed *dir;
  string tmp;
	if( !file ) return notify_fail("指令格式﹕edit <檔名>\n");
	if( this_player() != me ) return 0;
	if( in_edit(me) ) return notify_fail("你已經在使用編輯器了。\n");
	seteuid(geteuid(me));

    // If they haven't given an arguement as to what file...
    if (!file) file=(string)me->query("cwf");
    if (!file) { 
        write("Editg: [no file specified]\n");
        ed();
        return 1;
    }
    	file = resolve_path((string)me->query("cwd"), file);
    
    dir = explode(file, "/");
    tmp = implode( dir[0..sizeof(dir)-2], "/");
    if(tmp[0..0] != "/" ) tmp = "/"+tmp;
    if (file_size(tmp) != -2)
    {
    	write("Edit: [路徑錯誤]"+tmp+"\n");
    	return 1;
    }
    
    if (file_size(file)==-2) {
        notify_fail("Edit: 已經有相同名稱的目錄存在.\n");
        return 0;
    }
    write( "開始編輯檔案:"+file+"\n");
	ed(file);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : edit <檔名>, edit here

利用此一指令可直接在線上編輯檔案。
在 edit 下常用的指令或觀念:

用 增加(a), 取代(c) 啟動 'edit mode'.

要跳回 'command mode', 則在一行的起點輸入 '.' 再按 'enter' 鍵.

$ - 這個符號在 command mode 永遠都代表最後一行的行號.
:數字(n),(m)p ---- 列出檔案內容, n 為開始行號, m 為結束行號. 如果沒有
                   m,n 則列出 現在 所在行的內容. 如果 'p' 前只有一個數字
                   則列出數字所指行號的內容.
:數字(n),(m)d ---- 刪除由 n 到 m 行的內容. 如果 'd' 前只有一個數字, 則
                   刪除數字所指行號的內容.
:數字(n)a     ---- 在 n 行後加入東西. 於是進入 'edit mode'
:數字(n)i     ---- 在 n 行前加入東西. 於是進入 'edit mode'
:數字(n)c     ---- 修改第 n 行的內容. 於是進入 'edit mode', 之後
                   你所打入的東西都會取代第 n 行原有的內容.
              [註: 這個指令的 「有效」範圍是一行, 超過一行並不會讓你修改
                     n+1 行的東西.]
如果沒有指定行號, 則以目前所在行為準.
:x            ---- 存檔並離開 edit。
:q            ---- 離開 edit. [註: 此指令只適用於當檔案已經儲存過後, 或是檔案
                   沒有被更動過.]
:Q            ---- 如果檔案被動過, 但你不想寫入被更動的內容, 你可以用這個指
                   令離開 edit.
:!<cmd>       ---- 在 edit 下執行某些 mud 指令.
HELP
    );
    return 1;
}

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狐穴");

 set("long",@LONG
你現在來到狐狸穴的內部, 你走在一個伸手不見五
指的山洞裡, 你向更深處探頭看了看, 依然不能找到任
何光源, 在你的背後不遠處, 可以看到一絲絲亮光, 那
是你剛剛進來時的入口.... 
LONG
    );
 
 set("exits",(["northeast":__DIR__"en14",
               "south":__DIR__"en12",
           ]));
 set("no_clean_up", 0);
 setup();
}           

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","採藥者小屋");

 set("long",@LONG 
你置身於這棟一無所有的小屋中央, 發現因為多年沒有天梟
採藥者前來, 所以這棟小屋除了一些破舊的藥鋤及一堆堆的朽木
以外, 就只剩下一只小小的睡袋了....這裡的破舊果然是不言可
知的..........
LONG
    );
 set("exits",(["south":__DIR__"tree5",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}


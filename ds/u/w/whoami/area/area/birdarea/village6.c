#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"獵狐村"NOR"－"HIW"當鋪"NOR);
 set("long",@LONG
在你眼前是一家獵狐村當鋪, 有一位肥頭大耳, 小鼻小眼的
商人, 正在笑吟吟的看著你, 這裡的擺設, 雖然稱不上很華麗, 
不過東西卻不少.
LONG
    );
 
 set("exits",(["west":__DIR__"village5",
               ]));
 set("objects",([__DIR__"npc/shopman" : 1,
     ]));
 set("room_type","shop");
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        


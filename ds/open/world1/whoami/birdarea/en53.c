#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG 
你踩入泥沼區的同時你感覺到行動十分不便, 似乎快被泥沼
所吞噬, 四處散發著刺鼻的臭味, 讓人非常想吐. 你發現四處有
一些從未見過的昆蟲和植物, 不禁讚嘆大自然的奧妙.
LONG);
 set("exits",(["east":__DIR__"en54",
               "west":__DIR__"en52",
               "north":__DIR__"en51",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}


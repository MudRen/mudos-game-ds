#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
哇! 你一腳踏過來這裡就覺得渾身被一股殺氣壓迫著, 定眼
一看, 眼前盡是些說像狼不像狼, 說像虎不像虎的奇特猛獸, 你
看起來已經被牠們給圍住了....可是牠們看起來沒有主動攻擊你
的意思, 只是盯著你看, 不讓你輕舉妄動而已. 觀察了一下四周
地勢, 你覺得你來到了一處小迷宮中了.
LONG
    );
 set("exits",([ "east":__DIR__"jungle17",
                "west":__DIR__"jungle14",
                "south":__DIR__"jungle16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
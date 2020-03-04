#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹林中的小道");
 set("long",@LONG
你仍走在樹林間的小道路之上, 一路上並沒有什麼特別
的事物引你注意, 你總是把心思放在往向雲堂之路的上面.
LONG
    );
 set("exits",([ "south":__DIR__"mountroad3_3",
                "northeast":__DIR__"mountroad3_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
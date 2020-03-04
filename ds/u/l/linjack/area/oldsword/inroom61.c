#include <room.h>
inherit ROOM;
void create()
{
 set("short","密室");
 set("long",@LONG
打開了暗牆, 你才發現裡面竟然別有洞天! 這密室中實在
暗的不得了, 而且空氣很死, 你覺得有點喘不過氣來! 仔細看
看北面的牆上刻著奇怪的紋路.
LONG
    );
 set("exits",([ "east":__DIR__"inroom33",
                "west":__DIR__"inroom55",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

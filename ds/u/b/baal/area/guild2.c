#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"石廊"NOR);

 set("long",@LONG
這裡牆上每格幾步, 就掛著一盞油燈, 把走廊照的如白晝一般, 地板
看來是細心處理過的, 走在上面, 比城中的石版道還要舒服, 到了這裡, 
人慢慢多了, 但是每個天梟教徒看到你, 不但沒有原本那間石室裡那幾位
教徒的平靜, 反而都露出驚訝的表情, 而且都瞪著你瞧, 你被看的全身不
自在, 不禁想趕快找個地方躲起來...
LONG
    );
 set("exits",([ "west":__DIR__"guild1",
                "north":__DIR__"guild3",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}


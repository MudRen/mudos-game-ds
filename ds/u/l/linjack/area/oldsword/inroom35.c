#include <room.h>
inherit ROOM;
void create()
{
 set("short","奕之樓");
 set("long",@LONG
喔! 天吶! 這邊的風景可真漂亮. 你不禁贊不絕口的叫了起來. 
仔細看看四周才發現有兩個人正在這邊對奕, 品茶, 賞景. 可真幽
閒, 這兩個人似乎都內力深厚, 手勢輕翻就可以帶動鐵棋子, 極少
失手. 說不定他們是住在下面的翠碧樓喔. 北邊還有條天橋.
LONG
    );
 set("exits",([ "down":__DIR__"inroom29",
               "north":__DIR__"inroom36",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}

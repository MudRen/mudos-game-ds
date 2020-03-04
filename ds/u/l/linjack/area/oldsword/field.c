#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","荒郊野地");
 set("long",@LONG
這邊四處都有工人, 農夫, 十分努力的在工作, 打算把上國
再度繁榮起來. 樹都被砍倒了, 風一來就是一片黃沙滾滾的景象,
可見他們是在多惡劣的情況下為這裡奮鬥, 你不禁由心中發出那
麼一點點的感動.
LONG
    );
 set("exits",([ "west":__DIR__"mountdown9",
//                "east":__DIR__"unknown",
]));
 set("no_clean_up", 0);
 setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="east")
  write(YEL"\n你往回走到了疾風門一帶....一眨眼又是好幾天..\n\n"NOR);
 else if( dir=="west")
  write(YEL"\n你繼續往西走過拓荒帶...\n\n"NOR);
 return ::valid_leave(me, dir);
}

#include <room.h>
inherit ROOM;
void create()
{
 set("short","木屋中");
 set("long",@LONG
你來到了一個簡僕的木屋之中, 這屋子不大, 只能容下一個
人平日生活起居所需要的空間. 雖然這房子簡陋, 但是大體上還
算清潔. 你覺得有點奇怪, 牆上竟有掛一把十分耀眼的長矛和一
把長弓, 應該有人住在這, 桌上有些飯菜竟然還是熱的.
LONG
    );
 set("exits",([ "north":__DIR__"mountroad1_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
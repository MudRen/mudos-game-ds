//u/c/chiaa/world2/little flower_island/sand4.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", YEL"沙灘"NOR);
        set("long",@LONG
這裡是小花園的沙灘,海浪不時拍打著沙灘,
沙灘上散落著各種從海上飄來的木材與各式各樣
的貝殼,沙灘上偶爾有一些小生物爬行著~~

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       
       "south"      : __DIR__"rock1",    //岩石區1
       "southwest"  : __DIR__"rock2",    //岩石區2
  ]));
       
            setup();
replace_program(ROOM);
}

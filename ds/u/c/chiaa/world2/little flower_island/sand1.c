//u/c/chiaa/world2/little flower_island/sand1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", YEL"沙灘"NOR);
        set("long",@LONG
這裡是小花園的沙灘,海浪不時拍打著沙灘,
沙灘上散落著各種從海上飄來的木材與各式各樣的
貝殼,南方似乎有一座森林,透出一股陰森的感覺!!
沙灘上偶爾有一些小生物爬行著~~

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
       "northeast"  : __DIR__"ocean",     //海邊
       "west"       : __DIR__"sand2",     //沙灘2
       "south"      : __DIR__"forest1",    //森林1
  ]));
       
            setup();
replace_program(ROOM);
}

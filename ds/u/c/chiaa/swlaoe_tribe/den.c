//u/c/chiaa/swlaoe_tribe/den.c

#include <ansi.h>//定義色碼
inherit ROOM;    //定義房間

void create()
{
   set("short", "密室");
   set("long",@LONG
        一個昏暗的密室,你小心翼翼的注視前方的事物,
        忽然一個人影讓你的視線都轉移到他身上!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "up"   : __DIR__"salle2",   //大廳2
]));
            setup();
replace_program(ROOM);
}

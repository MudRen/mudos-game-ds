#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"滅骨峰-山腰"NOR);
 set("long",@LONG
這裡就是那棟建築物的前方了, 你發現這是一座青石製
成的神廟, 配上這山腰終年不散的寒霧, 頗有仙人出世之感! 
而這棟神廟前的門柱寫著《 善惡自有常道 》, 不曉得是什
麼意思? 而向下跳下去看來也沒有多高, 想必是下山的捷徑
了....?!
LONG
    );
 set("exits",([  "enter":__DIR__"ten40",
                 "down":__DIR__"ten29",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}


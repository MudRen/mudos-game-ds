#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
這裡是洞窟的底部,你感覺嚴熱的溫度漸漸下降了,你仔細一
瞧,前面是一大片的冰,你高興的跑了過去.....你慢步在冰
原之上,不一盞茶的時間,那酷熱的感覺就沒了,只有一股沁
心冰涼的舒暢感,你看到一位楚楚動人的女子就站在前面不
遠處
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "west" :"/u/t/tako/area/room~8.c",
  "east" :"/u/t/tako/area/room~6.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/girl.c" : 1,
]));      
  set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}






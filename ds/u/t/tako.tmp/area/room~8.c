#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
你走到冰原的內部,你只覺得愈來愈冷了,又想回到剛才的地方,
但你又想到如果回去的話又會很熱,你很矛盾的站在這裡想了一
刻,決定還是繼續的往前走,一探洞窟的深處
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "west" :"/u/t/tako/area/room~9.c",
  "east" :"/u/t/tako/area/room~7.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/woman.c" : 1,
]));      
  set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}







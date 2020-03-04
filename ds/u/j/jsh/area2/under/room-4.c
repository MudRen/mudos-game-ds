#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
來到這邊是一間灰暗的小房間，你手中的光線好像受到莫名的阻
礙似的，只能照亮你周圍三尺的空間，潮濕的霉味與四周的蜘蛛絲讓
你只想趕快離開。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room4",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/gloves-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


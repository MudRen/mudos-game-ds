#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
就像是道士抓鬼的情節一樣，這間密室到處都貼滿了符咒，特此
要壓住這邊的鬼怪，但是....似乎好像沒有什麼用處，你還是覺得有
東西一直在你的左右盤旋，遲遲不肯離去。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room3",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/cloak-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


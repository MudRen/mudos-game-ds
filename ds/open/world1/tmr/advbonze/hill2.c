#include <path.h>

inherit ROOM;

void create()
{
        set("short", "凌雲峰－山腳下");
        set("long", @LONG
你正走站在一條山道上，位於凌雲峰的山腳下，你不時可看到周
圍有不少的凌雲寺和尚往山峰上走去。相傳凌雲峰峰頂上有座純黃金
做的巨大金佛，約有十數人高，為佛教中的聖物，傳聞沒有佛緣的人
，終其一生，也沒有機會晉見巨大金佛像。
LONG
        );
        set("world", "past");
        set("exits", ([ /* sizeof() == 3 */
                "north" : __DIR__"hill3.c",
                "south" : __DIR__"hill1.c",
        ]));
        set("outdoors","forest");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



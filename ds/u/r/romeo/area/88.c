#include <ansi.h>
#include <path.h>
inherit ROOM;
void entercheck(object ob);
void create()
{
        set("short",HIR"戰國墳地-第一層"NOR);
        set("long", @LONG
這裡四周都是腐爛的屍體，都好像才死沒幾天，從到處散落的武器
看來，他們應該都是武者，而且武功也都還不錯，使用的都是一些名貴
的武器，快找找看，不一定有你合適的武器喔。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r1",
  "east" : __DIR__"r3",
]));
        set("world", "undefine");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "��ù�T�a");
        set("long", @LONG
test�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shiro9", 
]));
        set("no_clean_up", 0);

        setup();
}


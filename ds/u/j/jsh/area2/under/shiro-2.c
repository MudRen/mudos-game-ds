#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "��ù�T�a");
        set("long", @LONG
test�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shiro-3", 
  "south" : __DIR__"shiro-1", 
]));
        set("no_clean_up", 0);

        setup();
}


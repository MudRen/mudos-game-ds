#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "��ù�T�a");
        set("long", @LONG
test�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shiro4", 
  "south" : __DIR__"shiro2",  
  "northeast" : __DIR__"shiro_1",
  "northwest" : __DIR__"shiro-1",]));
        set("no_clean_up", 0);

        setup();
}



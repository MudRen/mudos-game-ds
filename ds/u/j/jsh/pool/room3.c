#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
紅色的軟沙，踩在上面，仿佛踩在火上面，你不時還會流汗，
你還會低下頭來，慢慢觀賞著這裡的紅沙，真是漂亮極了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room6",  
  "south" : __DIR__"room4",
  "north" : __DIR__"room2",
  "east" : __DIR__"room1",]));
        set("no_clean_up", 0);

        setup();
}


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"走廊"NOR);
        set("long", @LONG
你一出那個放滿數把武器的房間後，邊看到了一條寬闊的走道，
走道的兩側有數間的房間，你心裡一想，裡面住的人的名氣一定不會
小於剛才所出的房間主人。
LONG
 );       
        
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room13",
  "west"  : __DIR__"room16", 
  "east"  : __DIR__"room17", 
  "southwest" : __DIR__"room18",]));  
        set("no_clean_up", 0);
        setup();
}     


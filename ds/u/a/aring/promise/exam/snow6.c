#include <ansi.h>
inherit ROOM;

void create()
{
      set ("short", HIM"鵲泚溪"NOR);
      set ("long", @LONG
在這雪地裡居然還有未結冰的小溪，這一點就證明了此地生態環
境的怪異。旁邊有一小船，似乎可以利用此船，離開本地。
LONG);
      
  set("exits", ([ 
   "south" : __DIR__"snow5",  
   "enter" : __DIR__"boat", 
  ]));

  set("outdoors", "snow"); 
  set("no_clean_up", 0);

  setup();
}



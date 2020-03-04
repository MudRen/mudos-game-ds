#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"駭客"HIW"時空隧道"NOR);
  set ("long", @LONG
一到時空隧道，你看到這裡有台大螢幕，這就是惡靈所研發
的時空螢幕，目前只是在測試階段，所以只有幾個地方能夠
通行，東方是一條閃著黃光的隧道，是通往古代的，而西方
閃著藍光的則是通道現代的•
LONG);

 set("exits", ([ 
  "west" : "/open/world2/lichi_town_2/map_5_26",
  "east" : "/open/world1/tmr/area/hotel",
  "south" : "/u/h/hack/room01.c",
"wiz" : "/d/wiz/hall1",


]));
  set("objects", ([
        "/u/h/hack/item.c" : 1,
        ]) );  

  set("light",1);
  setup(); 

  replace_program(ROOM);
}

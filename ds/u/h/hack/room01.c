#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"駭客"HIW"控制中心"NOR);
  set ("long", @LONG
一到這個控制中心，這裡四通八達，可以通往許多地方，只
見此中心有著一台大型的電腦，想必這就是惡靈駭客的傑作
吧，這台電腦有者某種神奇的功效喔，從這裡往北邊是時空
隧道，東是惡靈工作室，西方目前正在興建中•
LONG);

  set("exits", ([ 
  "north" : "/u/h/hack/room02.c",
  "east" : "/u/h/hack/workroom2.c",
 "south" : "/u/h/hack/workroom.c",

]));
  
  set("light",1);
  setup(); 
call_other( "/obj/board/hack_b", "駭客留言板" );


  replace_program(ROOM);
}

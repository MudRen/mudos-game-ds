#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"無重力"HIW"科技走廊"NOR);
  set ("long", @LONG
一到這個工作室前廳，就看到了北方有一條高科技的隧道，
長度深不見底，隧道中佈滿了許多精密的儀器，不知道有什
麼用途，旁邊的小螢幕顯示著往北可以通到工作室的中心地
帶
LONG);

  set("exits", ([ 
  "north" : "/u/h/hack/room01.c",
 
]));
  set("valid_startroom", 1);
  set("light",1);
  setup(); 


  replace_program(ROOM);
}

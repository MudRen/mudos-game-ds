#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", RED"惡靈"HIW"工作室"NOR);
  set ("long", @LONG
一到這個工作室，就看到這裡有著一張大桌子，與一個櫃
貼滿了軟硬體的海報，後面有著一台杜比音響，正放著琇
琇的音樂，一到這裡就感覺到他的主人一定品味高雅喔.^^

LONG);

  set("exits", ([ 
  "west" : "/u/h/hack/room01.c",
 
]));
 
  set("light",1);
  setup(); 


  replace_program(ROOM);
}

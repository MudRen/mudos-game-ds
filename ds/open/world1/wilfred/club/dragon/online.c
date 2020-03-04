#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",HIC"�s�u��Բ�ѫ�"NOR);
  set("long",HIC"\n�o�̬O�ΨӰQ�׳s�u��ԹC�����a��C\n\n"NOR);
  set("exits", ([
  "down" : "/open/world1/tmr/area/hotel",
]));
  set("light",1);
  set("no_goto",1);
  setup();
  call_other("/obj/board/online_b" , "???");
}
void init()
{
  add_action("do_down","go");
}

int do_down(string str)
{
  if(str != "down") return 0;
  if(this_player()->query_temp("come_from_dragon"))
    this_player()->move("/open/world1/cominging/area/dragon/dragon");
  else
    if(this_player()->query_temp("come_from_sky"))
      this_player()->move("/open/world1/acme/area/sky/room35");
	else 
		if( this_player()->query_temp("come_from_moon")) // add by -alickyuen@ds-
			this_player()->move("/open/world1/acme/area/moon/room3");
    else return 0;
  return 1;
}


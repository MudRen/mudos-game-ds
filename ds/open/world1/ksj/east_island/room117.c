#include <room.h>
inherit ROOM;

void create()
{
  set("short","出雲山頂");
  set("long",@LONG
這裡是出雲山的山頂，四處岩石嶙嶇，佈滿斑斑白雪，強勁的冷
風挾帶雪花旋繞在岩石之間，你注意到有部份的岩壁好像被什麼東西
磨過似的，顯得比較光滑，地面上有些像是被撞碎的大岩塊。
LONG);
  set("exits",([ 
      "north":__DIR__"room115",
      "northeast":__DIR__"room116",
      "southdown":__DIR__"room108",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","snow");
  setup();
}   

int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("head", this_object())) && !me->query("orochi") && !random(3) && guard->is_character() )
  {
    message_vision("$n巨大的身體阻擋住$N的出路，$N一時手足無措，一臉驚慌。\n",me , guard);
    me->add_busy(1);
    return notify_fail("");
  }
  if( me->query("orochi_beast_3") )
  {
    if( dir == "southdown")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}                      


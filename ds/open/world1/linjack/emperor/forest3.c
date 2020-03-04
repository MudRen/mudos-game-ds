#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","密林中");
 set("long",@LONG
這是一片密林之中, 看起來光線格外的不足, 而且此處能平穩步行的地方
僅僅兩人之寬, 要是出現什麼猛獸就不好玩了. 咦? 你怎麼可以隱隱約約聽到
附近四周傳來一陣陣的腳步聲呢? 難道....
LONG);

 set("exits",([ "west":__DIR__"forest4",
                "southeast":__DIR__"forest2"]));
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}


void init()
{
 add_action("do_pick","pick");
}
int do_pick(string arg)
{
  object me,key;
  me=this_player();
  key = new(__DIR__"npc/obj/greenkey");
  if( !query("active_action") ) return 0;
  if( query("picked") ) return 0;
  if( me->is_fighting() || me->is_busy() ) return notify_fail("你正在忙耶!\n");
  if( !arg || ( arg != "key" && arg != "鑰匙" ) ) return notify_fail("你要撿什麼?\n");
  message_vision(HIB"$N突然從草叢間找出了一把鑰匙!\n"NOR,me);
  if( me->query_encumbrance() + key->query_weight() > me->query_max_encumbrance() ||
      me->query_capacity() + key->query("volume") > me->query_max_capacity() )
      key->move(environment(me)); 
  else key->move(me);
  set("picked",1);
  delete("item_desc");
  return 1;
}

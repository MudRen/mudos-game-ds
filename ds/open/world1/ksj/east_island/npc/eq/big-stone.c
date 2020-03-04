#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("巨石", ({"big stone","stone"}) );
  set("long",@LONG
一個巨大的石頭，像座小山似的擋住了山道，看來是岩層坍落造成的
，力量大的人或許可以移走(move)它。
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("no_sac",1);
    set("unit", "個");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_move","move");
}

int do_move(string str)
{
  object me;
  me=this_player();
  if(!str || str!="stone") return 0;
  if( me->query("str") < 110 ) return notify_fail("你使勁想移動巨石，無奈力氣不夠。\n");
  message_vision(HIW"\n$N雙手環抱，使盡吃奶的力氣慢慢地將巨石移動到一旁。\n"NOR,me);
  destruct(this_object());
  return 1;
}

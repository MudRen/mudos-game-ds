#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(MAG"蝕骨酸液"NOR,({"orochi acid","acid"}) );
  set("long",@LONG
八歧大蛇所吐出的酸液，快速地腐蝕所接觸到的任何物體。
LONG
);
  set_weight(30); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "灘");
    set("value",0);          
    set("volume", 1);                       
    set("material", "stone");
    set("no_sac",1);   
    set("no_sell", 1);
  }
  setup();
  call_out("dest_acid", 100);
  call_out("damage_by_acid", 3);
}

void damage_by_acid()
{
  object me = environment(this_object());
  int p_hp, i;

  if( !this_object() || !me ) return;
  if( interactive(me) )
  {
    p_hp = me->query("max_hp");
    me->receive_damage("hp", random(100)+50, this_object());
    message_vision("$N"HIR"劇烈地腐蝕$n的皮肉，痛得$n眼淚\直流！\n"NOR, this_object(),me);
    me->add_busy(1);
  }
  call_out("damage_by_acid", 3);
}

void dest_acid()
{
  destruct(this_object());
}

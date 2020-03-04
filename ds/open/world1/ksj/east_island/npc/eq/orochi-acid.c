#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(MAG"�k���ĲG"NOR,({"orochi acid","acid"}) );
  set("long",@LONG
�K�[�j�D�ҦR�X���ĲG�A�ֳt�a�G�k�ұ�Ĳ�쪺������C
LONG
);
  set_weight(30); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�y");
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
    message_vision("$N"HIR"�@�P�a�G�k$n���֦סA�h�o$n���\\���y�I\n"NOR, this_object(),me);
    me->add_busy(1);
  }
  call_out("damage_by_acid", 3);
}

void dest_acid()
{
  destruct(this_object());
}

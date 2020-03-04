#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(MAG"�G�r���Y"NOR, ({ "poison-snake pill","pill" }));
  set("long",@LONG
�@�����o�c�䪺�p�Y�l�A�Y�U�ỡ���w�|�z��{��C
LONG
);
  set_weight(50);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  string type,msg;
  object ob,me,env;
  me = this_player();
  ob = this_object();
  if( !ob ) return 0;
  if( !ob->id(arg) ) return 0;
  if( !env = environment(ob)) return 0;
  if( env != me && !ob->query("no_get")) return 0;
  if( me->is_busy() )
    return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
  me->receive_damage("hp",100,ob);
  me->apply_condition("poison", me->query_condition("poison")+(random(5)+15) );
  if( me->query_condition("blooding") > 5)
    me->apply_condition("blooding", me->query_condition("blooding")-(random(5)+1) );
  if( me->is_fighting() ) me->start_busy(2);
  message_vision(MAG"$N�Y�U�F�@���c�䪺���Y�Aı�o�{�z���h�L��...\n" NOR,me);
  destruct(ob);
  return 1;
}

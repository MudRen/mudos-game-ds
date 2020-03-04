#include <ansi.h>
inherit ITEM;

void create()
{ 
  set_name(CYN"�K��"NOR, ({ "bagi-power pill","pill" }));
  set("long",
      "�K���������ǧ��ġA��ɥR�j�q���K���l�D�E\n"
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
  me->add_temp("exert_mark/bagi-power",200);
  if( me->is_fighting() ) me->start_busy(2); 
  message_vision("$N�Y�U�F�@��$n�E\n" NOR,me,ob);
  destruct(ob);
  return 1;
}


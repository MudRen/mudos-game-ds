#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"���l�s��"NOR, ({"silver dragon heart","heart"}) );
  set("long", 
      "���l�s����Ŧ�A������j�p�A�o�X�B�N���H��C\n"
     );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",20);
    set("value",600);
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

  me->receive_heal("mp", me->query("max_mp") - me->query("mp"));
  me->apply_condition("poison", 0);

  if( me->is_fighting() ) me->start_busy(2);
  message_vision(HIW "$N���_�F�s�ߤj�f�a�Y�F�U�h�Aı�o�����M�Z�L��...\n" NOR,me);
  destruct(ob);
  return 1;
}

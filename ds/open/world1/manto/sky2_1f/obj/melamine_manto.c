
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIM"�T�E���i�C�Y"NOR, ({ "melamine manto","manto","objmanto" }));
  set("long",@LONG
2008�j�Ƭ����@�A��google�C

(���M�ߩ������n���n�A�O�աA���L�N�O���İʷQ�|�@�f(taste))

(�̤U���٦��@��X�G�ݤ��쪺�p�r�R���A��夣����ʽФp��)
LONG
);
  set_weight(999999999);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get", 1);
    set("no_sac", 1);
    set("no_put", 1);
    set("no_auc", 1);
    set("unit", "��");
  }
  setup();
}

void init()
{
  add_action("do_eat", "taste");
}

int do_eat(string arg)
{
  object ob,me;
  me = this_player();
  ob = this_object();
  if( !ob ) return 0;
  if( !ob->id(arg) ) return 0;
  if( me->is_busy() )
    return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
  me->receive_damage("hp",200,ob);
  me->apply_condition("poison", me->query_condition("poison")+(random(6)+5) );
  if( me->query_condition("blooding") > 5)
    me->apply_condition("blooding", me->query_condition("blooding")-(random(3)+1) );
  if( me->is_fighting() )   {  me->start_busy(2); }else{me->start_busy(1);}
  message_vision(HIM"$N���@�k�ݽ��]�@�U�A�רs�٬O�Ԥ����b�����r�F�@�p�f...\n" NOR,me);
  tell_object(this_player(),"�A�Pı�餺�����x�@�}�͵h"HIR"(200)�C\n"NOR);
  return 1;
}

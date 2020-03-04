#include <ansi2.h>
inherit ITEM;

void create()
{
  set_name(WHT"���O��"NOR,({"power tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�o�O�@�D���몺�ůȡA�ůȤW�g�F�@��_�Ǥ�r�A���ԵL��C\n�ϥΤ�k: power");
    set("value",2000);
    set("unit","�i");
  }
  setup();
}
void init()
{
  add_action("power","power");
}

int power()
{
  object me=this_player(), ob=this_object();
  if(ob->query("in_use")) return notify_fail("�@�i�u��Τ@���C\n");
  if(me->query_temp("power_tally_useing")) return notify_fail("�A������v�g�L�k�Ө���j���O�q�F�C\n");
  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  me->add_temp("apply/damage",150);
  me->set_temp("power_tally_useing",1);
  message_vision(HIR"$N�򴤤⤤��$n"HIR"�A�j�ܤ@�n�A��F�L�񪺮�l�|���ӥX�I�I\n"NOR,me,ob);
  call_out("out_contorl",100,ob,me);
  return 1;
}

int out_contorl(object ob,object me)
{
  if(!me) destruct(ob);
  me->delete_temp("power_tally_useing");
  me->add_temp("apply/damage",-150);
  write(HIR"�ʦL�󯫤O�Ť����O�q�v�����p�ɡA�Ʀ��H���b�Ť����R .... \n"NOR);
  destruct(ob);
  return 1;
}


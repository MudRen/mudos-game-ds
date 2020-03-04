#include <ansi2.h>
inherit ITEM;

void create()
{
  set_name(WHT"���t��"NOR,({"speed tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�o�O�@�D���몺�ůȡA�ůȤW�g�F�@��_�Ǥ�r�A���ԵL��C\n�ϥΤ�k: speed");
    set("value",4000);
    set("unit","�i");
  }
  setup();
}
void init()
{
  add_action("speed","speed");
  add_action("do_action","",1);
}

int speed()
{
  object me=this_player(), ob=this_object();
  if(ob->query("in_use")) return notify_fail("�@�i�u��Τ@���C\n");
  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  message_vision(HIY"$N�B�����u�A�N$n"HIY"��������A�µۦۤv�g�F�ӡy�e�z�r...\n\n�K�ɶ��A$N�����v�ܱo�a�g�_��...\n"NOR,me,ob);
  call_out("out_contorl",30,ob);
  return 1;
}

int do_action()
{
  if(!query("in_use")) return 0;
  this_player()->add_busy(-5);
  return 0;
}

int out_contorl(object ob)
{
  write(HIR"���t�Ū��ĤO�v�L�A�A�����v�]�����ܱo�M���i��... \n"NOR);
  destruct(ob);
  return 1;
}


#include <ansi2.h>
inherit ITEM;

void create()
{
  set_name(WHT"���O��"NOR,({"god tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�o�O�@�D���몺�ůȡA�ůȤW�g�F�@��_�Ǥ�r�A���ԵL��C\n�ϥΤ�k: god <�Y�ͪ����^��W>");
    set("value",3000);
    set("unit","�i");
  }
  setup();
}
void init()
{
  add_action("god","god");
}

int god(string str)
{
  object obj, me=this_player(), ob=this_object();
  if(ob->query("in_use")) return notify_fail("�@�i�u��Τ@���C\n");
  if(!str) return notify_fail("�п�J��誺�^��W�C\n");
  if( !(obj = present(str, environment(me))) )
    return notify_fail("�o�̨S�� " + str + "�C\n");
  if(userp(obj) || !living(obj))
    return notify_fail("�ϥι�H�O���X�k���C\n");
  obj->set("creater",me);
  ob->set("in_use",1);
  ob->set("no_sac",1);
  ob->set("no_sell",1);
  ob->set("no_drop",1);
  ob->set("no_give",1);
  set("value",0);
  message_vision(HIG"$N�|�_�⤤�����O�ų����G.....�K�ɶ��A"NOR"$n"HIG"���|�g�Q�@�D�����¶...\n"NOR,me,obj);
  message_vision(HIG"�u��"NOR"$n"HIG"�����g���A�v�g�������Q$N����F�C\n"NOR,me,obj);
  write(NOR""WHT"\n�{�b�A�u�n��J���O�A���N�|�ӵۧA���N���ʡC  ���O�榡�Rhest <��U> to <���O>\n"NOR);
  call_out("out_contorl",7,obj,ob);
  return 1;
}

int out_contorl(object obj,object ob)
{
  if(living(obj))
    obj->delete("creater");
  write(HIR"���O�Ū��ĤO�v�L!!\n���O�Ŭ�M�N�F�_��!!\n"NOR);
  destruct(ob);
  return 1;
}
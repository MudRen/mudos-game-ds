#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIC"�p���"NOR,({ "fun smoke","smoke" }) );
  set("long",HIM"�o�O�@��"HIC"�p"HIM"�o�ӱƤl����....�A�i�H��(suck)�ݬݡC\n"NOR);
  set("unit","��"); 
  set("food_remaining",1);
  setup();
}
void init()
{
  add_action("do_suck","suck");
}
int do_suck(string arg)
{
  object me = this_player();
  if(!arg || arg != "smoke") return 0;
  if( me->is_busy() )
  return notify_fail("�A�٦b��,����l��...\n");
  message_vision(HIC"$N�l�F�l��....�}�l�]���R���_��..�A�n���ּ֡C\n"NOR,me);
  me->start_busy(5);
  me->set_temp("suck1",1);
  call_out("start_suck",3,me,0);
  return 1;
}
int start_suck(object me,int f)
{
  if(!me) return 1;
  if(f < 4)
  {
    switch( random(3) )
  {
      case 0 : message_vision(HIY"$N��M���F��l...�y�F�@�y��..\n"NOR,me);           break;
      case 1 : message_vision(HIG"$N��M�Pı�����ƪ�...�n���W�F�Ѱ�@��\n"NOR,me);        break;
      case 2 : message_vision(HIR"$N��M�Pı����W���h�W..���T�s���F�_�ӡC\n" NOR,me); break;
  }
  call_out("start_suck",3,me,++f);
  return 1;
  }
  else message_vision(HIY"�����M�ǨӤF�p����ѨϪ��n��:!!!�l�Ϥ��n��!!!�C\n" NOR,me);
  if(this_player()->query_temp("suck1")>=5)
  {
  message("system",HIY"�W�Ťj�����G" +me->name(1)+ "�ѩ��F�Ӧh�ұo��F���������F...�U����_�_���n�l�ң�\n"NOR,users());
  }
  this_object()->add("fill_suck",-1);
  if( this_object()->query("fill_suck") < 1 )
  {
  this_player()->die();
  this_object()->delete("item_desc");
  set("long",HIM"�o�O�@��"HIC"�p"HIR"�o�ӵP�l����..�u�ѤU�ϸ�������,���G�w�g�⧹�F�C\n"NOR);
  set_name(HIC"�p��ҧ���"NOR,({ "fun smoke","smoke" }) );
  return 1;
}
}

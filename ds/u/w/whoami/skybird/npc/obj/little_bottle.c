#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("�p�~�l",({"litte bottle","bottle"}));
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�o�O�@�ӥά����s�����p�~�l�A�̭����˪��G��N�O�ѱ��t�u��\n"
               "�u���E���q�j���u��ϥΤ@���A�]�����O�b�U���o�w�����p�U�A\n"
               "�O���|�H�K�ʥΪ��E\n"
               "�ϥΤ�k�Guse bottle\n");
    set("value",0);
  }
  set("no_put",1);
  setup();

}

void init()
{
  add_action("do_use","use");
}

int do_use(string str)
{
  object ob = this_object(), me = this_player();
  if(!str || str != "bottle") return 0;
  if(  me->is_fighting() ) 
    return notify_fail("�o��E�P���԰��A�A�٦��߱��޶ˤf�H\n"); 
  if(  me->query("hp") >= me->query("max_hp")/3  )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if(  me->query("mp") >= me->query("max_mp")/3  )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if(  me->query("ap") >= me->query("max_ap")/3  )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if(  me->query("wound/left_arm") <= 60 )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if( me->query("wound/right_arm") <= 60 )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if( me->query("wound/right_leg") <= 60 )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if( me->query("wound/left_leg") <= 60 )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if( me->query("wound/body") <= 60 )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  if( me->query("wound/head") <= 60 )
    return notify_fail("�A�����p�٤��t�A���ݭn�Ψ�o�ا��ħa�E\n"); 
  me->receive_heal("hp", 3000); 
  me->receive_heal("mp", 3000);
  me->receive_heal("ap", 3000);
  me->receive_curing("all",100); 
  me->start_busy(2);
  message_vision(HIC"$N�p���l�l����~�l�̪�����٦b���˪��a��K�K\n"NOR,me);
  return 1;
}



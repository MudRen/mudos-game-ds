#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIR"�m��@���]�_��n"NOR,({"skyevil book","book"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
              "�o�O���]���@�ɩҥΪ��@���ѡA�O���o���]���Z�\��@�������E\n");
             }
        set("value", 100);
        set_weight(250);
        setup();
}

void init()
{
        add_action("do_you","you");
}

int do_you(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u��@���]�_��v�u���԰��������ϥΡC\n");

        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n");
        if( me->query("mp") < 90 || me->query("ap") < 120 )
                return notify_fail("�A�����骬�p���Ӧn�A�Ө�����o�j�P�������C\n");
        if( me->query_temp("you"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision(HIR"\n$N�ߤ���M����@���]�_�妳�F�{�P�P�A�_��K�ާA�l�X�u��@�������v\n\n"NOR,me);

        me->set_temp("you",1);
        me->start_busy(4);
        call_out("do_crazy",10, me, target,10);
        call_out("do_clean",10,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>35 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
      message_vision(HIR"\n$N����������M�]�ʥ����z�o�X�ӹ��"+target->query("name")+"�ۡG���a\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N���W�����N�M�]�ʤ��L�h�A�S�k��|�u��@�������v�C\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("you");
          return 1;
}


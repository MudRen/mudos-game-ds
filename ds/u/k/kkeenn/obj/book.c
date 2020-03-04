#include <ansi.h>
inherit SSERVER;
inherit ITEM;
void create()
{
        set_name(MAG"�z���_��"NOR,({"berserk book","book"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
     "�o�O�C�s�L��~���J�խߨФ���, ��H�ۨ����w, �ҦX������~�C\n");
             }
        set("value", 10000);
        set_weight(250);
        setup();
}
void init()
{
        add_action("do_berserk","berserk");
}

int do_berserk(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u�z�𭢡v�u���԰��������ϥΡC\n");

        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n");
        if( me->query("mp") < 50 || me->query("ap") < 100 )
                return notify_fail("�A�����骬�p���Ӧn�A�Ө�����o�j�P�������C\n");
        if( me->query_temp("berserk"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision(HIR"\n$N�����, �@���z��, ��h�~�������������X�ӡI�I\n\n"NOR,me);

        me->set_temp("berserk",1);
        me->start_busy(1);
        call_out("do_ber",1, me, target,20);
        call_out("do_serk",10,me);
        return 1;
}

int do_ber(object me,object target,int times)
{
  int i;
     if( random(100)>35 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("berserk");
      return notify_fail("�ؼзW�W�i�i���k���F..\n");
      return 0;
    }
     message_vision(HIR"\n$N���Ѫ��S�@�n�A���W�����B�X�@�����s�A���"+target->query("name")+"�I�i�X���Ǥ��ޡu"MAG"�z��"HIR"�v�I�I\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),20);
          me->receive_damage("ap",random(2));
          me->receive_damage("mp",random(2));
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N�Q��ŧ��, ��������f��, �ݨӨ��F�I���ˤF�C\n\n"NOR,me);
          me->receive_damage("hp",random(300));
   return 1;
   }
}
int do_serk(object me)
{
          if(!me) return 0;
          me->delete_temp("berserk");
          return 1;
}


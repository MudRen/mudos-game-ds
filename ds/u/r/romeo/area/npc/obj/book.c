#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
       set_name(HIR"�m�խ߯����_��n"NOR,({"you ming book","book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "��");
          set("long",
              "�o�O�@���u���@�����ѡA���M�u�O�@�����o��\n"
              "�O�F�Ѵݨ��ФQ�~�������~���g�Ӧ����A�ǻ�\n"
              "������@�f���z�o�H�鷥������A�����Y�u��\n"
              "�Ӧ�����j���i�խߡj�G�r�A�Τ@�Ǭݤ�����\n"
              "�Ÿ��A�ꤣ������γ~�C\n");
            }
        set("value", 0);
        set_weight(250);
                set("replica_ob",__DIR__"book2.c");
        setup();
}

void init()
{
        add_action("do_you","you");
}
int do_you(object target,string arg)
{
        object me;
        me=this_player();
      if( arg == "" ) return 0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u�խ߯����Z�v�u���԰��������ϥΡC\n");

        if (me->is_busy() )
                return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n");
      if(me->query("mp")<60 && me->query("ap")<100 ) return notify_fail("�A�����骬�p���Ӧn�A�Ө�����o�j�P�������C\n");
        if(me->query_temp("you"))
                 return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision(HIR"\n$N�𾮯��w�A�C�n���F�X�y�A��M�j�ܤ@�n�A�ǳƬI�i�X�u�խ߯����Z�v�I�I\n\n"NOR,me);

         me->set_temp("you",1);
         me->start_busy(2);
	me->receive_damage("hp",20);
         me->receive_damage("ap",80);
         call_out("do_crazy",4,me,target,6);
         call_out("do_clean",8,me);
         return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
if(me->query("mp")<30 && me->query("ap")<60 ) return notify_fail("�A�����骬�p���Ӧn�A�Ө�����o�j�P�������C\n");
     if( random(100)>30 && me->query("ap")>50 && me->query("mp")>30 )
  {
    if(!me) return 0;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
      message_vision(HIR"\n$N���Ѫ��S�@�n�A���������E�{�A���"+target->query("name")+"�I�i�X��@���ޡu�խ߯����Z�v�I�I\n\n"NOR,me);
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N�߷зN�áA�@�ɶ��Ϥ��X�u�խ߯����Z�v�C\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("you");
         return 1;
}

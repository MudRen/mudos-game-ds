#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
       set_name(HIC"�m����̡㤧����n"NOR,({"king book","book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "��");
          set("long",
"�o�O�@�i�g���o���կȡA�W�����������B�X�X�Ӧr\n"
"�Ÿ��A�ꤣ������γ~�C\n");
            }
        set("value", 0);
        set_weight(250);
                set("replica_ob",__DIR__"book1.c");
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
                return notify_fail("�u��I�q�v�u���԰��������ϥΡC\n");

        if (me->is_busy() )
                return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n";
      if(me->query("mp")<60 && me->query("ap")<100 ) return notify_fail("�A����;
        if(me->query_temp("you"))
                 return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision(HIR"\n$N�𾮯��w�A�C�n���F�X�y�A��M�j�ܤ@�n�A�ǳƬI�i�X;

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
if(me->query("mp")<30 && me->query("ap")<60 ) return notify_fail("�A�����骬�p�;
     if( random(100)>30 && me->query("ap")>50 && me->query("mp")>30 )
  {
    if(!me) return 0;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("you");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
      message_vision(HIR"\n$N���Ѫ��S�@�n�A���������E�{�A���"+target->query("n;
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      return 0;
   }
   else {
      message_vision(HIR"\n$N�߷зN�áA�@�ɶ��Ϥ��X�u��d�q�v�C\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("you");
         return 1;
}


#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
       set_name("�կ�",({"paper}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "�i");
          set("long",
              "�o�O�@�i�g���o���կȡA�W�����������B�X�X�Ӧr\n"
�@�@�@�@�@�@�@"�A�ΤO�@�ݭ�ӬO"MAG"����̡㤧���"NOR"�|�Ӧr\n");
            }
        set("value", 0);
        set_weight(110);
                set("replica_ob",__DIR__"book.c");
        setup();
}

void init()
{
        add_action("do_godie","godie");
}
int do_godie(object target,string arg)
{
        object me;
        me=this_player();
      if( arg == "" ) return 0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u���̤����v�u��b�԰����ϥΡC\n");

        if (me->is_busy() )
                return notify_fail("�A���W�@�Ӱʧ@�٨S�������A�A�B�\�N�|���\�F�C\n";
      if(me->query("mp")<60 && me->query("ap")<100 ) return notify_fail("�A����;
        if(me->query_temp("godie"))
                 return notify_fail("�A���ۦ��٨S�I�i�A�L�k�A�ϥΤF�C\n");
        message_vision(HIR"\n$N���餦�СA�k��@�ݡA�ǳƬI�i�X;

         me->set_temp("godie",1);
         me->start_busy(2);
        me->receive_damage("hp",30);
         me->receive_damage("ap",90);
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
      return notify_fail("���w�g���ۧ��ڶ]�F�C\n");
      return 0;
    }
      message_vision(HIR"\n$N�@�n�g�S�A�b$N�����e�X�{�@�f���C�A���"+target->query("n;
      for(i=0;i < times;i++)
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
      return 0;
   }
   else {
      message_vision(HIR"\n$N���M�@�f�A���X�f���A�@�ɶ��Ϥ��X�u���̤����v�C\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("you");
         return 1;
}


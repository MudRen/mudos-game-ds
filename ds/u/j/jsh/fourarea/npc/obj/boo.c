#include <ansi.h>
inherit SSERVER;
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIM"�}�ꪺ�}��"NOR,({"bad boo","boo"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
               "�n���O�����������_�� . . . �� . . . �ݤ��X�Ӧ�����"
               "�S�O���A�i�঳��L�γ~�a(exert_power)�C\n");
             }
        set("value", 100);
        set_weight(250);                set("replica_ob",__DIR__"boo2.c");
        setup();
}
void init()
{
        add_action("do_exert_power","exert_power");
}

int do_exert_power(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u�s���O�q�v�O�Ψӥ��ĤH��...\n");

        if( me->is_busy() )
                  return notify_fail("�A���ʧ@�٥������C\n");
        if( me->query("ap") < 10  )
                return notify_fail("�A����l�����F�A�h���I�^�ӦA�Χa�C\n");
        if( me->query_temp("exert_power"))
                return notify_fail("�A���b�Ψs���O�q�F�C\n");
        message_vision(HIC"\n$N�ťX�@����A�����}���A���Y�򴤨ð{�{�o���A���M�ۦa�@�n ! �                      �V�e�@�� ! ! �N�|�P�Ů𳣾_���s�s�@�T . . .                          �u�s�v                          �u���v 
                            �u���v
                              �u�q�v\n",me);

        me->set_temp("exert_power",1);
        me->start_busy(2);
        call_out("do_crazy",3, me, target,10);
        call_out("do_clean",10,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>40 && me->query("ap")>10  )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("exert_power");
      return notify_fail("�n���B ! ! �Q�L�k�F...\n");
      return 0;
    }
      message_vision(HIY"\n�u���v    �u�ءv     �u���v   ���V"+target->query("name")+"\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),1);
          me->receive_damage("ap",random(10)+10);
    }
      return 0; 
   }
   else {
      message_vision(HIM"\n$N���O�q���G�����W�ӡC\n\n"NOR,me);
          me->receive_damage("ap",50);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("exert_power");
          return 1;
}


#include <ansi.h>
inherit SSERVER;
inherit ITEM;
void create()
{
        set_name(HIG"���뱲�b"NOR,({"elf scroll","scroll"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
               "����өҽ�X�����뱲�b�Ať�������_���O�q(elf_power)�C\n");
             }
        set("value", 40000);
        set_weight(2000);     
  
        setup();
}
void init()
{
        add_action("do_elf_power","elf_power");
}

int do_elf_power(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u���뱲�b�v�O�Ψӥ��ĤH���C\n");

        if( me->is_busy() )
                  return notify_fail("�A���ʧ@�٥������C\n");
        if( me->query("ap") < 50  )
                return notify_fail("�A����l�����F�A�L�k�ϥΧ��뱲�b�C\n");
        if( me->query_temp("elf_power"))
                return notify_fail("�A���b�ϥΧ��뱲�b�C\n");
        message_vision(HIG"\n\t$N�ϥX���뱲�b�̪��O�q�A�@�i�S�@�i������A�q���b��«�X�I\n"NOR,me);
        me->set_temp("elf_power",1);
        me->start_busy(5);
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
      me->delete_temp("elf_power");
      return notify_fail("�n���B ! ! �Q�L�k�F...\n");
      return 0;
    }
      message_vision(HIR"\n�����ĥX�Q���a��A�H���p���α��ժ��t�סA�ɤ�$N��V"+target->query("name")+"\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),1);
          me->receive_damage("ap",random(10)+10);
    }
      return 0; 
   }
   else {
      message_vision(HIM"\n$N���O�q���G�����W�ӡC\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("elf_power");
          return 1;
}


#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;
void create()
{
  set_name( "�J�ۡE����" , ({ "longsword+3:Crom Feary","sword" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "���C+3�G�J�ۡE���̡A�Ѧ��_�����O�q" HIR "\n�������R(whirl dance of death)" NOR "\n���O�Gwdod\n");
    set("material", "wood");
    set("value",10000);
    set("volume",1);
  }
    set("limit_str",40);
    set("limit_level",30);
  init_sword(65);
  setup();
}

void init()
{
        add_action("do_wdod","wdod");
}

int do_wdod(string arg)
{
        object me, target;
        int time
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        if (( this_object()->query("equipped"))!="wielded")
                return notify_fail("�A�èS���˳ƦB���b!\n") ;
        if(!me->is_fighting())
                 return notify_fail("�A�ä��b�԰����I\n");
        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n");
        if( me->query_temp("wdod"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision( HIR "\n$N�j�ۡG�u�����ڪ��大����a�I�I\n\n"NOR,me);

        me->set_temp("wdod",1);
        me->start_busy(1);
        call_out("do_crazy",2, me, target, time);
        call_out("do_clean",4,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( me->query("hp")<150)
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("hits");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
      message_vision(HIC"\n$N���̬y�X��\�A�����o�X����A���"+target->query("name")+"�I�i�X�u�������R�v�I�I\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
    }
          me->receive_damage("hp",100);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N�_�����ɾ��٥������C\n\n"NOR,me);
   return 1;
   }
}
int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("wdod");
          return 1;
}

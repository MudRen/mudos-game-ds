#include <ansi.h>
#include <weapon.h>
#include "std_fist.c"
inherit SSERVER;

void create()
{
  set_name( HIY "�����M" NOR , ({ "ability gloves","gloves" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", HIY "�o�O�@���ίS����谵����M�A�W���x�ۤ@�ѴH��C\n�o���ݰ_�ӬO�k��Ϊ��C\n" NOR );
    set("material", "gold");
    set("value",1);
    set("volume",3);
  }
set("weapon_prop/hit",30);
set("weapon_prop/tec",1);
set("combat_msg", ({
   "$N�@���u�o���v�A�k�V�e�p��@�B�A�j�l���u�����V$n������\n",
   "$N�ϥX�u�_���O���v�A�|�_�k��b��W�j�F�@�f��A�@�D���$n�g�h\n",
   "$N�j���ਭ�A�a�D�J�šA�ϥX�u���Ѥ����v�A�b�Ť��d�U�@���Ӫ����B�W\n",
   "$N�N��𾮵��b�Y�v�W�A��$n���ݤf��h\n",
   "$N���F�_�ӡA��H��`�J����A�V$n�������W�F�@�U\n",
   "$N��a�����@�h���B�A�ƽ��V$n�����}\n",
}) );
  init_fist(150);
  setup();
}

void init()
{
        add_action("do_hits","hits");
        add_action("do_blizzard","blizzard");
        add_action("do_blizzard","bliz");
}

int do_hits(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u�����X�ʡv�u���԰��������ϥΡC\n");

        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n");
        if( me->query("mp") < 90 || me->query("ap") < 120 )
                return notify_fail("�A�����骬�p���Ӧn�A�Ө�����o�j�P�������C\n");
        if( me->query_temp("hits"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision( HIC "\n$N�ݨ����S�X�}��A��M�إ��@�{�A�ǳƬI�i�X�u�����X�ʡv�I�I\n\n"NOR,me);

        me->set_temp("hits",1);
        me->start_busy(2);
        call_out("do_crazy",2, me, target, random(6)+4);
        call_out("do_clean",4,me);
        return 1;
}

int do_crazy(object me,object target,int times)
{
  int i;
     if( random(100)>10 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("hits");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
      message_vision(HIC"\n$N�إ��@�{�A�����o�X�����A���"+target->query("name")+"�I�i�X�u�����X�ʡv�I�I\n\n"NOR,me);
      for(i=0;i < times;i++)
    {
      COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N�߷зN�áA�@�ɶ��Ϥ��X�u�����X�ʡv�C\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}

int do_blizzard(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u�H�V���{�v�u���԰��������ϥΡC\n");

        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n");
        if( me->query("mp") < 90 || me->query("ap") < 120 )
                return notify_fail("�A�����骬�p���Ӧn�A�Ө�����o�j�P�������C\n");
        if( me->query_temp("bliz"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision( HIC "\n$N�ݨ����S�X�}��A��M�إ��@�{�A�ǳƬI�i�X�u�H�V���{�v�I�I\n\n"NOR,me);

        me->set_temp("bliz",1);
        me->start_busy(2);
        call_out("do_bliz",2, me, target);
        call_out("do_clean",4,me);
        return 1;
}

int do_bliz(object me,object target)
{
  int i;
  int dmg;
  dmg = random(200)+random(300)+random(me->query("int")*10)+5000;
     if( random(100)>10 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("bliz");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
      message_vision(HIW"\n$N�إ��@�{�A�����o�X�ե��A���"+target->query("name")+"�I�i�X�u�H�V���{�v�I�I\n"NOR,me);
          target->receive_damage("hp",dmg);
          target ->start_busy(random(me->query("int"))/2);
          me ->start_busy(2);
          me->receive_damage("ap",random(7)+10);
          me->receive_damage("mp",random(7)+5);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N�߷зN�áA�@�ɶ��Ϥ��X�u�H�V���{�v�C\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}

int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("hits");
          me->delete_temp("bliz");
          return 1;
}

int query_autoload() { return 1; }


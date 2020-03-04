#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;
void create()
{
  set_name( "�j����P" , ({ "tow-hand-sword+2:spider killed","sword" }) );
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O�ѯS����ݻs��������C�A�㦳���i��ĳ���O�q�C\n");
    set("material", "iron");
    set("value",7000);
    set("volume",1);
  }
    set("weapon_prop/dodge",2);
    set("weapon_prop/hit",10);
    set("limit_str",20);
  init_sword(45,TWO_HANDED);
  setup();
}

int wield()
{
  object me;
  me = this_player();
  if(me->query("combat_exp") < 15000 )
  { return notify_fail("�A�g�礣���A�L�k�ϥλj����P�C"); }
  else { return ::wield(); }
}

void init()
{
        add_action("do_slash","slash");
}

int do_slash(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail( HIG " =SONIC SLASH= " NOR"�u���԰��������ϥΡC\n");

        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�S��C\n");
        if( me->query_skill("sword") < 60 )
                return notify_fail("�A���C�N�ޥ��٤����H�o��" HIG " =SONIC SLASH= " NOR "����O�C\n");
        if( me->query_temp("slash"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision( HIC "\n$N�ݨ����S�X�}��A��M�إ��@�{�A�ǳƨϥX" HIG " =SONIC SLASH= " NOR "�I�I\n\n"NOR,me);

        me->set_temp("slash",1);
        call_out("do_crazy",2, me, target);
        call_out("do_clean",4,me);
        return 1;
}

int do_crazy(object me,object target)
{
  int i;
     if( random(100)>10 && me->query("ap")>80 && me->query("hp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("slash");
      return notify_fail("�ؼЦ��G�����F�A�������d��..\n");
      return 0;
    }
      message_vision(HIW"\n$N�إ��@�{�A�����o�X�ե��A���"+target->query("name")+"�ϥX" HIG " =SONIC SLASH= " NOR "�I�I"NOR,me);
      target->receive_damage("hp",random(50)+random( me->query_skill("sword"))+100);
      me->receive_damage("ap",50);
      return 0; 
   }
   else {
      message_vision(HIR"\n$N�I�l�V�áA�@�ɶ��Ϥ��X" HIG " =SONIC SLASH= " NOR "�C\n\n"NOR,me);
          me->receive_damage("ap",30);
   return 1;
   }
}

int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("slash");
          return 1;
}


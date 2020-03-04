#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit SWORD;

void create()
{
  set_name(HIC"��C"NOR, ({ "ghost sword","sword" }) );
  set("long",@long
������һE�X�����C�A�ݰ_���a�a�����A�������C
long);      
  set_weight(10);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "steel");
    set("value",0);
    set("volume",0);
  }
  set("weapon_prop/sou",1);
  set("weapon_prop/hit",10);
  set("weapon_prop/dex",2);
  init_sword(30);
  setup();
}

void attack(object me, object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->query("id") == "warrior ghost")
  {
    if( !random(7) )
    {
      message_vision(HIR"$N�����q���A���$n�@�}�s��r��I\n"NOR,me,victim);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
      COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
      me->start_busy(2);
    }
  }
  else
  {
    call_out("dest_obj",30);
  }
  return;
}

void dest_obj()
{
  message_vision("\n$N"HIW"�Ƭ������ƴ��b�Ť��C\n\n"NOR,this_object());
  destruct(this_object());
}
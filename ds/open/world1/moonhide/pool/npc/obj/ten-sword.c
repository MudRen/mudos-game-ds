#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
  set_name(HIC"�Q��ѷ�"NOR , ({ "ten-destruct sword","sword" }) );
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�E�ݬO�ⴶ�q���¼C�A�C�b�W���t���F�\\�h�a��A���@���@�۬�M�⮩��\n"
                "�]�\\�o�ǵ����O�S�N�s�y�X�Ӫ��A�γ\\�i�H..[break_sword]\n");
    set("material", "gold");
    set("value",30000); 
    set("no_sell",1);
  }
  set("weapon_prop/str",1);
  set("weapon_prop/con",1);
  set("weapon_prop/dex",1);
  set("weapon_prop/bar",-1); 
  set("weapon_prop/wit",1);
  set("weapon_prop/parry",-5);
  init_sword(45); 
  setup();
}

void init()
{
    add_action("do_break_sword","break_sword");
}

int do_break_sword(string arg)
{
  object me,victim;
  me = this_player();  
  if( !me->is_fighting() )
    return notify_fail("�A�S���b�԰��C\n");
  victim = me->select_opponent();
  message_vision(HIR"�w $N�N�Q��ѷ����b�a�W�A�b�N�C���_���P�ɡA�j�ۡy�����}�Q��z �w\n"NOR,me);
  me->start_busy(2); 
  if(random(3) > 2)
  {
    message_vision(HIC"�Q��ѷ�"HIW"�_�Ʀ��L�ƸH���A"HIR"���V"+victim->query("name")+"�I\n"NOR,me);  
    COMBAT_D->do_attack(me, victim, this_object(), 5);
    COMBAT_D->report_status(victim);
    victim->add_busy(5);   
    victim->receive_damage("hp",2000+random(1500));
  } 
  else
  {
    message_vision(HIC"�Q��ѷ�"HIW"�_���D�`����A$N�����N�O�G�y���Ϧw��!!??�z\n"NOR,me); 
    tell_object(me,"[��觹���S���췴���}�Q�誺�ˮ`]\n");
    me->add_busy(3);
  } 
  destruct(this_object());
  return 1;
}

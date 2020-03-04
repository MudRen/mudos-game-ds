// ���ӭn�� string short() �ӱ����� [�ܦ�]
// ��ӵo�{�b�԰��� sk ���ˬd���O���� set �� name
// �ҥH�� set ���ܦ�        wilfred@DS
#include <ansi2.h>
#include <weapon.h>
#include <combat.h>
#define NAME "�ֶ��C"
#define ID "(Sho-yang sword)"

inherit F_UNIQUE;
inherit SWORD;

void create()
{
  set_name(NAME, ({ "sho-yang sword", "sword" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", @LONG
���C���W�j���L�Сy�ӷ��C�z�Ҥ����X�Ӫ��@��C�A���ݶ��A
�E�ݤ��U���C���H�L�_�A�ڻD�u���a�ۧl�����C���H�԰�����
���o�����褧��A�~�ധ�o���C���¤O�C
LONG
);
    set("value",20000);
    set("material", "steel");
  }
  set("limit_skill",70);
  set("weapon_prop/str",3);
  set("weapon_prop/int",-2);
  init_sword(63);
  setup();
  set("power",1);
}

void attack(object me,object victim)
{
  int index = 10;
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;

  add("power",1);
  if(query("power") > (index * 4 + 5))
    message_vision(HIC"\n$N�P��@�ѱj�l���O�q�X���q�餺�z�o�X�ӡI�I�I\n\n"NOR,me);
  if(query("power") > (index * 4 + 5))
  {
    if(me->is_busy()) return;
    me->start_busy(2);
    victim->start_busy(2);
   message_vision(HIR"$N"HIR"���C����$n"HIR"�A$n�@�ɶ��Q$N�j�l���C�����o�z���L��ӡI\n"NOR,me,victim);
    call_out("super",1,me,victim);
  }
  switch(query("power") / index)
  {
    case 1 : set_name(HIW""BLK"" +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
    case 2 : set_name(NOR""WHT"" +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
    case 3 : set_name(HIW"" +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
    case 4 : set_name(HIR +NAME+ ""NOR, ({ "sho-yang sword", "sword" }) );
             break;
  }
  return;
}

void super(object me, object target)
{
  int damage = random(800)+400;

  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N�N�ʧ@�����F�C\n",me);
    return;
  }
  if(environment(me) != environment(target))
  {
    message_vision("$N�]����⤣�b�����F��աC\n",me);
    return;
  }
  if(me->query("ap") < 210)
  {
    message_vision(HIC"���G����Ƴ��S�o�� .....\n"NOR,me);
    this_object()->set("power",1);
    write(this_object()->name(1)+"�S�t�H�F�U�� ....\n"NOR);
    return;
  }

  message_vision(NOR+WHT"�K�ɶ��A�C��Φ����ե��H���֪��t�׾����]��b$N"NOR+WHT"�����W.....\n"NOR,target);
  message_vision(HIW"\n\t�y�F�I�I�I�z��ե����z��$N"HIW"�餺�ɡA��p�}�Ѧӭ��I$N"HIW"�����G�D���p�z���L�I�I�I"HIR"("+damage+")\n\n"NOR,target);
  message_vision(HIR"$N"HIR"�Q�����ƤV���A���b�Ť����x�A���٤H��......\n\n"NOR,target);

  target->add_busy(3);
  target->set_temp("define_look",HIR"[���g���A]"NOR);
  call_out("delay_look",4,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 200, me);
  me->start_busy(2);
  this_object()->set("power",1);

  COMBAT_D->report_status(target);
  set_name(NAME, ({ "sho-yang sword", "sword" }) );
  write(this_object()->name(1)+"�S�t�H�F�U�� ....\n"NOR);
  return;
}
void delay_look(object target)
{
  if(!target) return;
  target->delete_temp("look_define");
  message_vision(HIG"\n$N�C�C���M���F�L��.....\n\n"NOR,target);
}

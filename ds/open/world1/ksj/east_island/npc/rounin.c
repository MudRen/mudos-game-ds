#include <ansi.h>
#include <combat.h>     
inherit NPC;

void create()
{
  set_name("���H", ({"rounin"}));
  set("long",@long
�|�B�y�����Z�̡A�����O�y�`���Z�h�A�]�����O�|�B�������C�ȡA��
�����H�Z���Ʀܤ񥿦��D�����v�d�ٱj�C
long);      
  set("gender", "�k��" );
  set("age",37);
  set("level",37+random(5));
  set("race","human");
  set_skill("blade", 50+random(30));
  set_skill("parry", 40);
  set_skill("dodge", 50);
  set_skill("unarmed", 50);
  set("talk_reply","�D�D�D�D�D\n");
  add("addition_armor",50);
  setup();
  carry_object(__DIR__"eq/raikiri-katana")->wield();
  add_money("coin",1000+random(500));
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }

  if(target->query("level") > me->query("level")) return 0;
  if( (me->query("level")-target->query("level"))>0 && !random(5) )
  {
    message_vision(HIW"\n$N�ϥX�G���󥭪k�̰��Ҭɡ�"HIC"�ߤ��@��"HIW"�A�q���������o�j�j�����N\n"
                  +"�A$n�Q���N�_���M�����L�k�ʼu�C\n\n"NOR, me, target);
    target->add_busy(3);
    return 1;
  }

  return 0;
}

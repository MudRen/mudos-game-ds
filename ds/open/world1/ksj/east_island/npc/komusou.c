#include <ansi.h>
inherit NPC;

void create()
{
  set_name("��L��", ({"komusou"}));
  set("long",@long
�Y�W���۶굩�Τ���\���i�y�աA���W�ܵ۳P�ơA�V�W���۲ڥסA
��j����ƽt���M�|�A�ݥL�⤤���Z�����j�A�i��O�Ӻj�k����C
long);      
  set("gender", "�k��" );
  set("age",43);
  set("evil",-20);
  set("level",41);
  set("race","human");
  set_skill("fork", 80);
  set_skill("parry", 60);
  set_skill("dodge", 80);
  set_skill("unarmed", 60);
  add("addition_armor",45+random(5));
  set("talk_reply","�o�Ӵ˪L���j���ۿ@�p������A���D�ߧ��N�b�˪L���H\n");
  set("chat_chance", 5);
  set("chat_msg", ({
      "��L���q������z�X�U�Q�������A�J�Ӧa���q�۴˪L�|�P�D�D\n",
      "��L����Ӥ⤤�a�ϱ�ۥ_�軡�D�G��D�D���ӴN�b����C\n",
      "��L���a�ۤ@�ʾ𧤤F�U�ӡA���X�h������³�C�C�a�Y�ۡC\n",
     }));
  set("inquiry/�ߧ�","�����A���ơA�^�U�A�̦n�������}�C\n");
  setup();
  switch( random(50) )
  {
    case  0..48: carry_object(__DIR__"eq/kikuchi-pike")->wield(); break;
    case 49: carry_object(__DIR__"eq/dragonfly-cut-pike")->wield(); break;
  }
  carry_object(__DIR__"eq/forest-map");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  add_money("coin",700+random(500));
}

int special_attack(object me, object target, int hitchance)
{
  int damage,lv;
  lv=target->query("level");
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;

  if( (me->query("hp"))  < (me->query("max_hp")/3))
  {
    if(!random(6) && me->query("ap") > 200 && me->query_temp("weapon"))
    {
      damage=(75-lv)*8+random(100);
      message_vision(HIR"\n$N�Ԧ�˶աA�D�V�b�šA�⤤���j�Ʀ��L�ƺj�Bŧ�V$n�A\n"
        +RED"$n�uı�o�����E�h�A���W�G���Ƥ��M���˲��I�C"HIR"("+damage+")\n\n"NOR,me, target);
      target->receive_damage("hp",damage,me);
      target->add_busy(2);
      target->apply_condition("blooding", target->query_condition("blooding")+(random(5)+10));
      me->receive_damage("ap",100,target);
      me->receive_damage("hp",100,target);
      message_vision(HIR"\n$N�R�F�@�j�f�A��I\n"NOR,me);
      return 1;
    }
    else if(me->query("ap") < 200)
    {
      command("eat water pill");
    }
    else
    {
      command("eat food pill");
    }
  }
  else if(!random(7) && me->query("ap") > 100 && me->query_temp("weapon"))
  {
    damage=(60-lv)*7+random(80);
    message_vision(HIC"\n$N�⤤���j�@�ݡA�j�y���ƦP�����V$n���|�ϡA\n"
    +RED"$n�����D�ӫ��{�����ڡA��}�w�Q�����뤤�I�C"HIR"("+damage+")\n\n"NOR,me, target);
    target->receive_damage("hp",damage,me);
    me->receive_damage("ap",100,target);
    return 1;
  }

  return 0;
}

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("虛無僧", ({"komusou"}));
  set("long",@long
頭上戴著圓筒形斗笠蓋住整張臉孔，身上披著袈裟，頸上掛著缽皿，
邊吹蕭邊化緣的和尚，看他手中不凡的長槍，可能是個槍法高手。
long);      
  set("gender", "男性" );
  set("age",43);
  set("evil",-20);
  set("level",41);
  set("race","human");
  set_skill("fork", 80);
  set_skill("parry", 60);
  set_skill("dodge", 80);
  set_skill("unarmed", 60);
  add("addition_armor",45+random(5));
  set("talk_reply","這個森林裡瀰漫著濃厚的妖氣，難道貓妖就在森林內？\n");
  set("chat_chance", 5);
  set("chat_msg", ({
      "虛無僧從斗笠中透出銳利的眼光，仔細地打量著森林四周．．\n",
      "虛無僧比照手中地圖望著北方說道：嗯．．應該就在那邊。\n",
      "虛無僧靠著一棵樹坐了下來，拿出懷中的乾糧慢慢地吃著。\n",
     }));
  set("inquiry/貓妖","不關你的事，奉勸你最好趕快離開。\n");
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
      message_vision(HIR"\n$N忍住傷勢，躍向半空，手中長槍化成無數槍雨襲向$n，\n"
        +RED"$n只覺得全身聚痛，身上佈滿數不清的傷痕！。"HIR"("+damage+")\n\n"NOR,me, target);
      target->receive_damage("hp",damage,me);
      target->add_busy(2);
      target->apply_condition("blooding", target->query_condition("blooding")+(random(5)+10));
      me->receive_damage("ap",100,target);
      me->receive_damage("hp",100,target);
      message_vision(HIR"\n$N吐了一大口鮮血！\n"NOR,me);
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
    message_vision(HIC"\n$N手中長槍一抖，槍尖分化同時擊向$n的四肢，\n"
    +RED"$n不知道該怎麼閃躲之際，手腳已被狠狠刺中！。"HIR"("+damage+")\n\n"NOR,me, target);
    target->receive_damage("hp",damage,me);
    me->receive_damage("ap",100,target);
    return 1;
  }

  return 0;
}

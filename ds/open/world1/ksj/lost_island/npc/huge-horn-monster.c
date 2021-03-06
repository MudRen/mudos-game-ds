#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW"紗牙羅獸"NOR, ({"huge horn monster","monster"}) );
  set("long",@LONG
全身長滿白色長毛的奇獸，頭上長了一根向後彎曲的巨角，牠的頭比
起角來就顯得小多了，據說牠的角所製成的號角發出的聲響可以穿山
過海。
LONG);
  set("race", "beast");
  set("unit","隻");
  set("age",125);
  set("gender", "雄性" );
  set("level",42+random(4));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴","前腳","後腳" }) );
  set("verbs", ({ "bite","crash","claw"}) );
  add("addition_damage",45+random(10));
  set("chat_chance", 10);
  set("chat_msg", ({
   HIW"紗牙羅獸"NOR"的巨角突然冒出淡淡的光芒。\n",
   HIW"紗牙羅獸"NOR"用巨角撞向一旁的小樹，樹幹應聲而斷。\n",
     }));
  setup();
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  switch( random(99) )
  {
    case  0..98: new(__DIR__"eq/horn-bugle")->move(this_object());
    break;
  }
  ::die();
  return;
}

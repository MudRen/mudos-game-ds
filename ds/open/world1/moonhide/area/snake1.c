inherit NPC;
void create()
{
  set_name("小蛇", ({"little snake","snake"}) );
  set("long",@LONG
一條兇惡的小蛇。
LONG
);
  set("race", "beast");
  set("unit","條");
  set("age",5);
  set("level",15);
  set("limbs", ({ "頭部", "腹部","胸部","尾巴" }) );
  set("verbs", ({ "bite" }) ); 
  setup();
  add_money("coin",100);
}



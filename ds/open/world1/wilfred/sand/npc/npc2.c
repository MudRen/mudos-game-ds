inherit NPC;

void create()
{
  set_name("黑狼", ({"black wolf","wolf"}) );
  set("long",@LONG
這是在黃沙平原上一種十分兇狠的狼，但平常不會主動攻擊人類。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",7);
  set("level",16);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",100);
}

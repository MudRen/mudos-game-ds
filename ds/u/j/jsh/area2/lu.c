inherit NPC;

void create()
{
  set_name("一點露", ({"someone lu","lu"}) );
  set("long",@LONG
為安排在古墓迷宮陣的平衡守護者.....與石魔齊驅。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1021);
  set("level",40);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",100);
}


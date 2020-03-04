inherit NPC;

void create()
{
  set_name("黃狼", ({"yellow wolf","wolf"}) );
  set("long",@LONG
這是一種生長在乾旱之地的狼種，十分兇狠，但平常不會主動攻擊人類，
性好群居，白天休息，晚上會結伴出外覓食。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",5);
  set("level",15);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",100);
}

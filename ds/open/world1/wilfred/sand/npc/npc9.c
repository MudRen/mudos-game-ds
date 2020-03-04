inherit NPC;

void create()
{
  set_name("熊", ({"bear"}) );
  set("long",@LONG
十分巨大的熊，經常出沒在山區域之間，而且非常具攻擊性。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",4);
  set("level",24);
  set("attitude", "aggressive");
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  carry_object(__DIR__"eq/eq7")->wear();
}

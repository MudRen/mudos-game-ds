inherit NPC;

void create()
{
  set_name("守護石獸", ({"stone beast","beast"}) );
  set("long",@LONG
一個石頭製成的野獸，面目兇惡，但看不出是什麼動物，這石像可能已有百年的光景了。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",100);
  set("level",30);
  set("limbs", ({ "頭部", "腹部","胸部","爪子" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
}


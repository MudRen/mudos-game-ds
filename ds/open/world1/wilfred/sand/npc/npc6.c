inherit NPC;

void create()
{
  set_name("�f��", ({"dragonfly"}) );
  set("long",@LONG
�b���䳣�i�ݨ����f���C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",1);
  set("level",2);
  set("con",1);
  set("limbs", ({ "�Y��", "����","�ݳ�" }) );
  set("verbs", ({ "bite" }) );
  setup();
  add_money("coin",10);
}

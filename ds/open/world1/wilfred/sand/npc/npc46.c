inherit NPC;
void create()
{
  set_name("��ɦu��", ({ "boundary guard","guard" }) );
  set("long","�n�u�ɿ���Ҥ��u�áA���ɳƦ��T�ϡA�Y�F�z�j�s�ӥǮɧY�i�ΥH��ĵ�C\n");
  set("level",20);
  set("age",40);

  set("combat_exp",29000);
  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
(: command("say �A�N�O�F�z�j�s�ܡH�ݧګ�򦬬B�A�I") :),
}));
  set_skill("parry", 70);
  set_skill("unarmed", 76);
  set_skill("dodge", 65);
  setup();
  add_money("coin",100);
}

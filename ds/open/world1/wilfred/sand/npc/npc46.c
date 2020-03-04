inherit NPC;
void create()
{
  set_name("邊界守衛", ({ "boundary guard","guard" }) );
  set("long","駐守滄縣邊境之守衛，平時備有狼煙，若沙漠大盜來犯時即可用以示警。\n");
  set("level",20);
  set("age",40);

  set("combat_exp",29000);
  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
(: command("say 你就是沙漠大盜嗎？看我怎麼收拾你！") :),
}));
  set_skill("parry", 70);
  set_skill("unarmed", 76);
  set_skill("dodge", 65);
  setup();
  add_money("coin",100);
}

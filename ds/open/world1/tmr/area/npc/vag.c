inherit NPC;

void create()
{
	set_name("流氓",({"vag"}) );
	set("long",
		"一個看來流里流氣的傢伙，正不懷好意地看著你..。\n"
	);		
	set("age",23);
	set("level",3);
      set("attitude", "heroism");

	set("evil",40);		
	set("race","人類");

	set("chat_chance",10);
	set("chat_msg",({
                (:command("say 前兒日子賭贏了百來兩，真辣塊媽媽的好運！"):),
		(:command("hehe"):),
	})	);

        set("chat_chance_combat", 17);
   	set("chat_msg_combat", ({
	(:command("say 老子今日就讓你見識見識何為「流氓打法」！！"):),
         }) );
	set_skill("dodge",10);
	set_skill("parry",10);
	set_skill("blade",5);
	set_skill("unarmed",5);
	
	setup();
	carry_object(__DIR__"wp/knife")->wield();
	carry_object(__DIR__"eq/furrier")->wear();
	carry_object(__DIR__"obj/dice");
	add_money("coin",50);
}

inherit NPC;

void create()
{
	set_name("釣客",({ "fisher" }) );
	set("long","一個正坐在河邊、拿著釣竿，悠閒地釣魚的釣客。\n");
	set("race","人類");
	set("age",25);
	set("level",3);
	set("attitude","friendly");
	
	set("chat_chance",10);
	set("chat_msg",({
	(:command("say 魚兒魚兒快上釣，好讓本爺添口福。"):),
	(:command("say 生平最大樂事，不外乎「超渡魚蝦」，哈哈哈！！。"):),
	}) 
	);
	set_skill("staff",10);
	set_skill("parry",10);
	set_skill("dodge",5);
	set_skill("unarmed",5);
	setup();
	carry_object(__DIR__"../wp/rod")->wield();
	carry_object(__DIR__"../eq/suncap")->wear();
}

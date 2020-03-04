// child.c

inherit NPC;

void create()
{
	set_name("阿雅", ({ "aya" }) );

	set_skill("stealing", 40);
	set_skill("dodge", 25);
	set_skill("dagger", 20);
	set_skill("parry", 20);

	set("level",5);
	set("age", 15);
	set("gender", "女性");
	set("long",
"這個十三，四歲的小姑娘就是「阿雅」了﹐看她身上雖然髒兮兮地，\n"
"卻十足是個美人胚子﹐一雙水汪汪的大眼睛骨碌碌地轉著﹐還不時盯著\n"
"你看﹐使你不禁覺得有些發窘。\n"
);
	set("chat_chance",5);
	set("chat_msg",({
		(:command("sing"):),
		"阿雅高聲唱道：「嗨∼∼照過來∼∼眼睛不要放口袋∼∼」\n",	
	}) );
	setup();
	add_money("coin", 50);
	carry_object(__DIR__"eq/heart_cloth")->wear();
	carry_object(__DIR__"wp/dagger")->wield();
}


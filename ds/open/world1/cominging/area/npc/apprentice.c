inherit NPC;
void create()
{
	set_name("小弟子", ({ "second apprentice", "apprentice" }) );
	set("long", "一個疾風門新收入的小門徒，大概是剛從市井之地而來，\n"
		    "身上還帶有一點油脂味。\n");

	create_family("疾風門",4,"弟子");
	set("class","fighter");
	set("attitude","friendly");

	set("level",10);
	set("age",  18);
	set("chat_chance",9);
	set("chat_msg",({
  "小弟子互相練著劍。\n",
  (: command,"sweat" :),
}));

	set_skill("sword",  20);
	set_skill("dodge",  20);
	set_skill("parry",  25);
	set_skill("sorgi_sword",15);
	map_skill("sword","sorgi_sword");
	set_skill("fogseven",20);
	map_skill("dodge","fogseven");

	setup();
	carry_object(__DIR__"wp/longsword")->wield();
	carry_object(__DIR__"eq/flyboots")->wear();
}
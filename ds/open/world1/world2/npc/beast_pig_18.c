
inherit NPC;

void create()
{
	set_name("母山豬", ({"wild female pig","pig"}) );
	set("long", "一頭十分巨大的山豬，這隻巨大的山豬似乎很討厭外人侵入牠的地盤。\n");
	set("unit","頭");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 24);
	set("level",18);
	//set_temp("fly",1);
	set("attitude", "aggressive");
	set("chat_chance",1);
	set("chat_msg",({
//		(: this_object(), "random_move" :),
		"母山豬很用力的瞪著你看。\n",
	}));

	setup();
}

void die()
{
	object pork;
	int i;
	for(i=0;i<9;i++)
	{
		pork=new_ob(__DIR__"../obj/pork");
		pork->move(this_object());
	}
	::die();
}
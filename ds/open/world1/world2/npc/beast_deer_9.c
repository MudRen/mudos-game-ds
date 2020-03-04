inherit NPC;

void create()
{
	set_name("山鹿", ({"deer"}) );
	set("long",@LONG
一隻褐色的山鹿，頭上頂著一對長角。
LONG);
	set("unit","頭");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof","horn" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 3);
	set("level",9);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<3;i++)
	{
		meat=new_ob(__DIR__"../obj/deermeat");
		meat->move(this_object());
	}
	::die();
}
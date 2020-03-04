inherit NPC;

void create()
{
	set_name("水牛", ({"buffalo"}) );
	set("long",@LONG
一頭十分巨大的水牛，頭上頂著一對捲曲的牛角。
LONG);
	set("unit","頭");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof","horn" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age",7);
	set("level",14);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<10;i++)
	{
		meat=new_ob(__DIR__"../obj/beef");
		meat->move(this_object());
	}
	::die();
}
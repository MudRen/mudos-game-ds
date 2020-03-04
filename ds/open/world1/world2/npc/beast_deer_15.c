inherit NPC;

void create()
{
	set_name("白尾鹿", ({"white-tail deer","deer"}) );
	set("long",@LONG
一頭難得一見的白尾鹿，身型巨碩，雪白的尾巴上還長滿了利刺。
LONG);
	set("unit","頭");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof","tail","horn" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 7);
	set("level",15);
	//set_temp("fly",1);

	setup();
}


void die()
{
	object meat;
	int i;
	for(i=0;i<5;i++)
	{
		meat=new_ob(__DIR__"../obj/deermeat");
		meat->move(this_object());
	}
	::die();
}
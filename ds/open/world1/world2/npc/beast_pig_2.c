inherit NPC;
void create()
{
	set_name("乳豬", ({"baby pig","pig"}) );
	set("long",@LONG
可愛的小豬仔，在地上滾來滾去。
LONG);
	set("unit","隻");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("str",1);
	set("con",1);
	set("level",2);
	set_temp("apply/hit",-20);      //弱化命中率
	set_temp("apply/dodge",-20);    //弱化閃躲率
	setup();
//	carry_object(__DIR__"../obj/pork");
}

void die()
{
	object pork;
	int i;
	for(i=0;i<2;i++)
	{
		pork=new_ob(__DIR__"../obj/pork");
		pork->move(this_object());
	}
	::die();
}
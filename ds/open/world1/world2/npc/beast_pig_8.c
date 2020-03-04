inherit NPC;
void create()
{
	set_name("母豬", ({"female pig","pig"}) );
	set("long",@LONG
一頭肥嘟嘟的大母豬，躺在地上打瞌睡。
LONG);
	set("unit","頭");
	set("race", "beast");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 5);
	set("level",8);
	setup();
//	carry_object(__DIR__"../obj/pork");
}

void die()
{
	object pork;
	int i;
	for(i=0;i<6;i++)
	{
		pork=new_ob(__DIR__"../obj/pork");
		pork->move(this_object());
	}
	::die();
}
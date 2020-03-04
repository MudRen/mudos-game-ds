
inherit NPC;

void create()
{
	set_name("野豬", ({"wild pig","pig"}) );
	set("long", "這隻野豬有著長長的兩顆獠牙，看起來不太好惹。\n");
	set("unit","頭");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "前蹄", "後腿", "肚子","屁股" })); //受攻部位
	set("verbs", ({ "bite","crash","hoof" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 8);
	set("level",15);
set_temp("apply/hit",-20);      //弱化命中率
set_temp("apply/dodge",-20);    //弱化閃躲率
	//set_temp("fly",1);
	set("chat_chance",1);
	set("chat_msg",({
		(: this_object(), "random_move" :),
		"野豬很兇的衝向你，你很快的往旁邊閃過了。\n",
	}));

	setup();
	carry_object(__DIR__"obj/pork");
	carry_object(__DIR__"obj/pork");
}

inherit NPC;
void create()
{
	set_name("大肚魚", ({ "dadu fish","fish" }) );
	set("race", "beast");
	set("gender","fish"); //會遺留在屍體上的set
	set("age", 1);
	set("level",1);
        set("long", @LONG
一隻小小的大肚魚，是貓兒們最喜歡的點心。
LONG);
	set("str",1);
	set("max_hp",10);
	set("dex",1);
	set("int",1);
	set("unit","尾");
	set("limbs", ({ "頭部", "身體", "尾鰭", }) );
	set("verbs", ({ "bite", "poke","crash" }) );
	set("corpse_id","deadfish");
	set("corpse_name","死大肚魚");
	setup();
}

void die()
{
	object meat;
		meat=new_ob(__DIR__"../obj/fishmeat");
		meat->move(this_object());
	::die();
}
inherit NPC;
void create()
{
	set_name("鯉魚", ({ "carp" }) );
	set("race", "beast");
	set("gender","fish"); //會遺留在屍體上的set
	set("age", 1);
	set("level",3);
        set("long", @LONG
一隻活潑的鯉魚，嘴巴不停的一開一合。
LONG);
	set("str",3);
	set("max_hp",30);
	set("dex",2);
	set("int",1);
	set("unit","尾");
	set("limbs", ({ "頭部", "身體", "尾鰭", }) );
	set("verbs", ({ "bite", "poke","crash" }) );
	set("corpse_id","deadcarp");
	set("corpse_name","死鯉魚");
	setup();
}

void die()
{
	object meat;
	int i;
	for(i=0;i<2;i++)
	{
		meat=new_ob(__DIR__"../obj/fishmeat");
		meat->move(this_object());
	}
	if(random(16)==0)
	{
		meat=new_ob(__DIR__"../eq/copper_ring");
		meat->move(this_object());
	}
	::die();
}
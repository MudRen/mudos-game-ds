inherit NPC;
void create()
{
	set_name("�j�{��", ({ "dadu fish","fish" }) );
	set("race", "beast");
	set("gender","fish"); //�|��d�b����W��set
	set("age", 1);
	set("level",1);
        set("long", @LONG
�@���p�p���j�{���A�O�ߨ�̳̳��w���I�ߡC
LONG);
	set("str",1);
	set("max_hp",10);
	set("dex",1);
	set("int",1);
	set("unit","��");
	set("limbs", ({ "�Y��", "����", "���_", }) );
	set("verbs", ({ "bite", "poke","crash" }) );
	set("corpse_id","deadfish");
	set("corpse_name","���j�{��");
	setup();
}

void die()
{
	object meat;
		meat=new_ob(__DIR__"../obj/fishmeat");
		meat->move(this_object());
	::die();
}
inherit NPC;
void create()
{
	set_name("�U��", ({ "carp" }) );
	set("race", "beast");
	set("gender","fish"); //�|��d�b����W��set
	set("age", 1);
	set("level",3);
        set("long", @LONG
�@�����⪺�U���A�L�ڤ������@�}�@�X�C
LONG);
	set("str",3);
	set("max_hp",30);
	set("dex",2);
	set("int",1);
	set("unit","��");
	set("limbs", ({ "�Y��", "����", "���_", }) );
	set("verbs", ({ "bite", "poke","crash" }) );
	set("corpse_id","deadcarp");
	set("corpse_name","���U��");
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
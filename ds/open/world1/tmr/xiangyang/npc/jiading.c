// jiading.c �a�B

inherit NPC;

void create()
{
	set_name("�a�B", ({ "jia ding", "jia" }));
	set("gender", "�k��");
	set("age", 35);
	set("long", "�����a�B�C\n");

	set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	setup();

}


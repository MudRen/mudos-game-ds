
inherit NPC;

void create()
{
    set_name("����", ({ "cow" }) );
	set("race", "beast");
	set("age", 5);
	set("level", 2);
    set("long", "�@�Y���������C\n");
	set("attitude", "peaceful");
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
    set("verbs", ({ "kick", "bite" }) );


	setup();
}
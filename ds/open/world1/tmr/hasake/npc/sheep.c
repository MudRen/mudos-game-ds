inherit NPC;
void create()
{
    set_name("����", ({ "sheep" }) );
	set("race", "���~");
	set("age", 5);
	set("level", 10);
    set("long", "�@�Y���եi�R�A�S�ΤS�������ϡC\n");
	set("attitude", "peaceful");
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
    set("verbs", ({ "kick", "bite" }) );
    set("skin", __DIR__"obj/yangpi");
	setup();
}

#include "skin_drop.c"

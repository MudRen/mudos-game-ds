#include <ansi.h>
inherit  __DIR__"war_base.c";

void create()
{
	set_name("����", ({ "crazy bear", "bear", "animal-war-object" }) );
	set("long", @BCD
�@�����S����, ����|�������~, �髬�]���e�j�C
BCD	);
	set("title", HIY"�g"NOR); // War �� Mob
	set("unit","��");

	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}", "���x" })); //���𳡦�
	set("verbs", ({ "crash","bite", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 10);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));

	set("war_score", 1);
	set("age", 30);
	set("level", 29);
	set("str", 55);
	set("con", 65);
	set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C

	setup();
	set_living_name("animal-war-object");
	carry_object(__DIR__"obj/meat");
	carry_object(__DIR__"obj/meat");
}

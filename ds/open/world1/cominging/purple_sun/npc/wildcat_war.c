#include <ansi.h>
inherit  __DIR__"war_base.c";

void create()
{
	set_name("����", ({ "crazy cat", "cat", "animal-war-object" }) );
	set("long", @LONG
�@�����S����, ����|�������~�C
LONG	);
	set("title", HIY"�g"NOR); // War �� Mob
	set("unit","��");
	set_living_name("animal-war-object");

	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}" })); //���𳡦�
	set("verbs", ({ "crash","bite", "claw", "hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 10);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));

	set("war_score", 1);
	set("age", 30);
	set("level", 26);
	set("str", 45);
	set("con", 58);
	set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C

	setup();
	set_living_name("animal-war-object");
	carry_object(__DIR__"obj/meat");
	carry_object(__DIR__"obj/meat");

}
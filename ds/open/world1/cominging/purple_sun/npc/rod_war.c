#include <ansi.h>
inherit  __DIR__"war_base.c";

void create()
{
	set_name("����", ({ "crazy hawk", "hawk", "animal-war-object" }) );
	set("long", @LONG
�@�����S����, ����|�������~, �b�Ť�����, ���������C
LONG);
	set("title", HIY"�g"NOR); // War �� Mob
	set("unit","��");

	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}", "�ͻH" })); //���𳡦�
	set("verbs", ({ "crash","bite", "claw", "poke" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 10);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));

	set("war_score", 1);
	set("age", 25);
	set("level", 25);
	set("str", 36);
	set("dex", 44);
	set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C
	set("fly",1);

	setup();
	set_living_name("animal-war-object");
	carry_object(__DIR__"obj/meat");
	carry_object(__DIR__"obj/meat");
}

#include <ansi.h>
inherit  __DIR__"war_base.c";

void create()
{
	set_name("�r��", ({ "crazy tiger", "tiger", "animal-war-object" }) );
	set("long", @LONG
�@�����S����, ����|�������~, ���W���������G�ݰ_�ӴN����@��, �O�H���H��Ÿ�C
LONG
	);
	set("title", HIY"�g"NOR); // War �� Mob
	set("unit","��");

	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}", "����" })); // ���𳡦�
	set("verbs", ({ "crash","hoof", "claw" })); // �������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 10);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));

	set("war_score", 1);
	set("age", 32);
	set("level", 31);
	set("str", 62);
	set("con", 61);
	set("attitude", "aggressive"); // �D�ʧ���,�ͩʦn������ NPC�C

	setup();
	set_living_name("animal-war-object");
	carry_object(__DIR__"obj/meat");
	carry_object(__DIR__"obj/meat");

}
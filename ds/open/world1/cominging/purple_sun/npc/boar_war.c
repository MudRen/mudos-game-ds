#include <ansi.h>
inherit  __DIR__"war_base.c";

void create()
{
	set_name("�s��", ({ "crazy boar", "boar", "animal-war-object" }) );
	set("long", @LONG
�@�����S����, ����|�������~, �e���f���٦��ۤ@�ƪ��y��, �O�H���Ǯ��ߡC
LONG	);
	set("title", HIY"�g"NOR); // War �� Mob
	set("unit","��");

	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}", "���Y" })); //���𳡦�
	set("verbs", ({ "crash","hoof", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 10);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));

	set("war_score", 1);
	set("age", 30);
	set("level", 24);
	set("str", 30);
	set("con", 44);
	set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C

	setup();
	set_living_name("animal-war-object");
	carry_object(__DIR__"obj/meat");
	carry_object(__DIR__"obj/meat");

}
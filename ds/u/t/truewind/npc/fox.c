// This is a npc made by npcmaker.
#include <ansi.h>
inherit NPC;

void create()
{
	set_name( WHT"�Ȫ�"NOR, ({ "fox" }));
	set("long", "�o�O�@���u�b���s�W�X�S�������A�e����A���ơA�D�`���d�C\n");
	set("age", 1);
	set("level",1);
	set("race", "beast");
	set("verbs", ({ "bite", "claw" }) );
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("chat_chance", 10);
        set("chat_msg", ({
           (: random_move :),
           ("�Ȫ��R�R���|�B�i��ۡC\n"),
}) );
        
	setup();
}

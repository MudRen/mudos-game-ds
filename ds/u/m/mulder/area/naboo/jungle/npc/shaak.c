#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"�F�["NOR, ({"shaak"}) );
        set("race", "���~");
        set("age",20);
        set("level",5);
        set("attitude","friendly");    
        set("long","�F�[�O�H���ũM,�͵����ʪ��C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("chat_chance",70);
        set("chat_msg",({
	(: "random_move" :),
        }) );
        set("verbs", ({ "bite", "claw","hoof" }) );
        setup();
}

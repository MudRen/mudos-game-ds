#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�j�Ǻ�",({"big bear","bear" }) );
        set("level",28);
        set("race", "���~");
       set("age",15);
        set("long", "�e�O�@���㦳�����ʪ��j�Ǻ��C�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}

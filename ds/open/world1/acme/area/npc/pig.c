#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����",({ "pig" }) );
        set("race", "���~");
        set("age",6);
        set("long", "�e�O�ͬ��b�`�s�����ޡA�ݨӬ۷��j���A�٪��F�������y���C\n"
);
        set("level",14);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                "���ޥΥL���y�����a�W���F�X�U�A�����b��ԣ����C\n", }) );
        setup();
}

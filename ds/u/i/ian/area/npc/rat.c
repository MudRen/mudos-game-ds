#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�p�ѹ�",({"little rat","rat"}));
        set("level",2);
        set("race", "���~");
        set("age", 2);
        set("long", "�o�O�@���Q�A�~�쪺�p�ѹ��C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}

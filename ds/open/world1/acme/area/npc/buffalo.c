#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "����" , ({ "buffalo" }) );
        set("level",10);
        set("race","���~");
        set("con", 19);
        set("age",6);
        set("long",
                 "�o�O�@���b�и����A�Ҽ��Ъ����C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}


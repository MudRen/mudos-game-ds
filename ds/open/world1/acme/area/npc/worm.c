#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�F��", ({ "worm" }) );
        set("race", "���~");
        set("age", 5);
        set("long", 
            "�e�O�@���ܤj���ΡA������x��j�A�u���e��F�]�F�i�h\n"
            "�A�S�R�F�X�ӡA�����b��ԣ�C\n",
            );
        set("level",2);
        set("dex",-1);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite"}) );
        setup();
}


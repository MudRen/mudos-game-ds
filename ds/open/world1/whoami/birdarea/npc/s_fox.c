#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�p���W",({"small fox","fox"}));
        set("level",10);
        set("race", "���~");
        set("age", 14);
        set("max_hp",5000); 
        set("max_ap",5000);
        set("max_mp",5000);
        set("long", "�o�O�@���p�p�����W�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�p�D", ({ "small snake","snake" }) );
        set("race", "���~");
        set("age", 1);
        set("long", "�p�p���@���D�A�u���O�p�p�����C\n");
        set_skill("dodge",50);
        set_skill("unarmed",40); 
        set_skill("parry",30);        set("level",20);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite" }) );
        setup();
}


#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"Honey"NOR, ({ "honey","dog" }) );
        set("race", "���~");
        set("age", 3); 
        set("title",HIY"�g�A�Q����"NOR);        set("level",1);
        set("long", "Jangshow ���d���C\n");
        set("str",1);
        set("max_hp",10);
        set("dex",-3);
        set("int",1);
        set("con",1); 
        set("no_kill",1);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                "Honey�λ�l�D�F�D�A���}�C\n",
                "Honey��ۧA�n�F�n���ڡC\n",
                "Honey�Ϋ�L��F�쨭��C\n" }) );
                

        setup();
}



#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"�_���s"NOR, ({ "baby dragon","dragon","baby" }));
        set("long","���s�������p�p�s�A���������ˤO�C\n");

        set("race","���~");
        set("level", 1);
        set("age", 100);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}


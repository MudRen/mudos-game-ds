#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�����s"NOR, ({ "fly dragon","fly","dragon" }));
        set("long","�s�����䪺�@�áA�㦳�@�w�����ˤO�C\n");

        set("race","���~");
        set("level", 13);
        set("age", 533);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}


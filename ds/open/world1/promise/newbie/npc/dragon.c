#include <ansi.h>
inherit NPC;
void create()
{
        set_name(WHT"�ܤ��s"NOR, ({ "dragon" }));
        set("long","���s�����ܤƦh�ݪ��s�ءC\n");

        set("race","���~");
        set("level", 9);
        set("age", 333);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}


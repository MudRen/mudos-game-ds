#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"�U�~�s"NOR, ({ "thousand year dragon","dragon","year" }));
        set("long","���s����������`�A���̵M���������ˤO�C\n");

        set("race","���~");
        set("level", 3);
        set("age", 1000);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}


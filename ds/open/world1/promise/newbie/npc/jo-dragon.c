#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"�U�˵��s"NOR, ({ "jo dragon","dragon","jo" }));
        set("long","�s�����䪺�@�áA�㦳�@�w�����ˤO�C\n");

        set("race","���~");
        set("level", 11);
        set("age", 433);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}



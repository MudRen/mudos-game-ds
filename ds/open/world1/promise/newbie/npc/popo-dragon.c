#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"�w�w�s"NOR, ({ "popo dragon","popo","po","dragon" }));
        set("long","���s�����̱j�ժ��s�ءC\n");

        set("race","���~");
        set("level", 10);
        set("age", 333);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}


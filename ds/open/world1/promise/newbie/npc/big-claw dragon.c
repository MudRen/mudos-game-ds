#include <ansi.h>
inherit NPC;
void create()
{
        set_name(CYN"�����s"NOR, ({ "big claw dragon","dragon","big" }));
        set("long","���s�����\\�O�y�L�j���s�ءC\n");

        set("race","���~");
        set("level", 7);
        set("age", 100);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name(YEL"��Ž�s"NOR, ({ "long dragon","dragon","long" }));
        set("long","���s�����s�u�áA���\\�O�y�L���z�C\n");

        set("race","���~");
        set("level", 5);
        set("age", 200);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"����"NOR, ({ "fly tiger","tiger","mob" }));
        set("long","basic���d�����@�C\n");

        set("race","���~");
        set("level", 31+random(5));
        set("age", 2);

        set("limbs", ({ "���Y","���","���","�ꨭ","�e�}","��}","�겴","���@" }) );
        set("verbs", ({ "bite", "claw","poke" }));

        set_temp("apply/attack", 3);
        set_temp("apply/damage", 20);
        set_temp("apply/dodge", 40);
        set_temp("apply/armor", 15);

        set("combat_exp", 10000000);
        setup();
        add_money("silver",2);
}

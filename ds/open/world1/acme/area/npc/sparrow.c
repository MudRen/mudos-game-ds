#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�³�" , ({ "sparrow" }) );
        set("level",1);
        set("race","���~");
        set("age",1);
        set("dex",-1);
        set("long","�o�O�@���p�p���³��C\n");
        set("limbs", ({ "�Y��", "����", "����" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�F��", ({ "warrigal ghost","ghost", "__GUARD__" }) );
        set("level",24);
           set("combat_exp",2400);
set("exp",1000);
        set("long","�L�O�@��������۬��⪺�k���C\n");
        set("age",30);
        set("evil",30);
set("title",CYN"���X���S"NOR);
        set("gender","�k��");
        set("attitude","killer");
            set_skill("unarmed",48);
          set_skill("dodge",48);
           set_skill("parry",48);
        setup();
}

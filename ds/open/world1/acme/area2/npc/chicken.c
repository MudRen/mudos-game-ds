#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "弱雞" , ({ "feeble chicken","chicken", "__GUARD__" }) );
        set("level",5);
        set("age",5);
       set("gender","雌性");
           set("combat_exp",500);
        set("evil",9);
        set("race","野獸");
               set("attitude","killer");
        set("long","身體已變形不像一隻尋常的雞，爪之利、嘴之尖，相當駭人。\n");
        set("limbs", ({ "頭部", "身體", "翅膀", "尾巴" }) );
        set("verbs", ({ "claw", "poke" }) );
        setup();
}

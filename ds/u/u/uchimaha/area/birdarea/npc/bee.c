#include <ansi.h>
inherit NPC;
void create()
{
       set_name("變種虎頭蜂",({"tigerhead bee","bee"}));
        set("level",14);
        set("race", "野獸");
        set("age", 23);
        set("long", "兇猛的一種蜂類，雖然是蜂類，但是他卻用爪子來攻擊人。\n");
        set("limbs", ({ "頭部", "身體", "翅膀", "爪子"}) );
        set("verbs", ({ "claw"}) );
        setup();
}

#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(GRN"槐枝厲爪"NOR,({"pagoda claw","claw"}) );
        set("long","這是由槐樹枝及人骨組成的一對厲爪，殺生之氣極重，膽小之人根本沒法子拿。\n");
        set_weight(3000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
                set("unit", "對");
        }
                set("value", 16000);
                set("material","gold");
                set("weapon_prop/int", 2);
                set("weapon_prop/str", 1);
                set("weapon_prop/hit", 5);
                set("volume",2);
                set("limit_int", 40);
                set("limit_level", 30);
        init_fist(55);
        setup();
}


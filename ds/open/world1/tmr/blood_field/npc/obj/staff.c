#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG"綠草杖"NOR,({"green staff","staff"}));
		set("long",
		  "這是一根用不知名的綠草編織而成的法杖，有著你從來沒見過的法紋。\n"
		);
        set_weight(15000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "根");
            set("value",3000);
             set("volume",4);
        }
        set("weapon_prop/int",1);
		init_staff(40);
        setup();
} 

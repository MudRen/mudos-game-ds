#include <weapon.h>

#include <ansi.h>

inherit FIST;

void create()
{
    set_name(HIY"耀日爪"NOR, ({"sun fist","fist"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "對");
         set("long", "一對爪子,說輕不輕,說重也不重。\n");
         set("value", 150);
         set("wield_msg","$N把$n套在手上。\n");
         set("unwield_msg","$N把$n拿下來。\n");
         set("weapon_prop/str", 3);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 5);
         set("weapon+prop/int", 5); 
    }

    init_fist(70);
    setup();
}









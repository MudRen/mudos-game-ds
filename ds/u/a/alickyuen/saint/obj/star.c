
#include <armor.h> 
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIY"星形耳環"NOR, ({ "star-shaped earring","earring" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一對星星形狀的耳環，\n"
                           "你可以試著配帶看看。\n");
                set("unit", "對");
  set_temp("has_light",1);  
                set("material", "jade");
set("value",1000);
		set("wear_msg",HIY"$N戴上了這對耳環， 突然覺得一片光明。"NOR);
        }
        setup();
}

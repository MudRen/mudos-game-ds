//u/c/chiaa/obj/eq/shadow_cloak.c
#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
   set_name(WHT"幻影"BLU"披風"NOR,({"shadow cloak","cloak"}) );
   set("long","一件很輕很薄的披風.\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5555);
                set("material", "gauze");  //薄紗
                set("unit", "件");                          
                set("armor_prop/armor", 15);
                set("armor_prop/shield",6);
                set("value",300);
        }
        setup();
}

#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name(HIW"白長衫"NOR,({ "white linen","linen" }) );
        set("long","用亞麻加工染色的長衫，可以防止輕微的傷害。\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "件" );
        set("value",1000);
        set("armor_prop/armor", 3); 
        set("armor_prop/con", 1); 
        } 
        setup();
}
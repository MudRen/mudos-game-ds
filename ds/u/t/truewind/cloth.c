#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name( WHT"陰"HIW"陽"NOR"二氣袍", ({ "Twin-kee robe","robe" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "道家的密袍，上頭繡了陰陽二氣的氣團圖案。");
        set("unit", "件");
        set("value",1);
        set("material", "silk");  
         }
        set("armor_prop/armor", 10 );
        set("armor_prop/show_damage",1);
        setup();
}
int query_autoload() { return 1; }

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"萬能袋"NOR, ({"multirole bag","bag" }) );
        set("long", @long
附重量比往常的袋子多很多。 
long);
          set_weight(2000);
        set_max_capacity(52);
        set_max_encumbrance(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("volume",2);
                set("value",1000);
        }
        setup(); 
}


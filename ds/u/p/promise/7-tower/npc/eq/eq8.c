#include <armor.h>
#include <ansi.h>
inherit HEAD; void create()
{
        set_name(NOR+RED"金鳳盔"NOR, ({ "gold phoenix helmet","helmet" }) );
        set_weight(400);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","\n上古火鳳凰之皮所做成的頭部防具。\n"NOR);
                set("unit", "個");
                set("value",5000);
                set("material","gold");
                set("armor_prop/str",1);
                set("armor_prop/con",1); 
                set("armor_prop/int",-2);
                set("armor_prop/dex",-1);                set("armor_prop/bar",-1);
                set("armor_prop/wit",1);
                set("armor_prop/armor", 3);
                set("limit_lv",40);
                set("limit_str",50);
                set("limit_con",50); 
                set("limit_int",30);
                set("limit_dex",35);
        }
        setup(); 
}



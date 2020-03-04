#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
        set_name(CYN"闇魔手"HIR"(S)"NOR,({"dark gloves","gloves"}) );
        set("long",@LONG
潛藏在幽暗之地的邪魔，用其雙手製成的皮手套，雖然難看但防禦能
力不錯。
LONG
);
        set_weight(600); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙");       
                set("value",2500);          
                set("volume", 2);                       
                set("material", "fur");   
        }
        set("armor_prop/armor",9);       
        setup();
}

int query_autoload() { return 1; }

#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIY"修羅金面"NOR,({"shu-lou gold mask","mask","gold mask"}) );
        set("long",@LONG
擁有修羅憤怒面的面具，讓人看了不寒而慄。
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "個");       
                set("value",2000);          
                set("volume", 2);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/int",2);
        setup();
}



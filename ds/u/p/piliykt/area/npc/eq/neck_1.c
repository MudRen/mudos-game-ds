#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(WHT"珍珠項鍊"NOR,({"june-juw neck","neck"}) );
        set("long",@LONG
由許多顆的珍珠編串而成,看起來美觀又漂亮,又有防禦效果.
LONG
);
        set_weight(800); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_lv",20);               
                set("female_only",1);
                set("unit", "條");       
                set("value",4200);          
                set("volume", 4);                       
                set("material", "glass");   
        }
        set("armor_prop/armor",6);       
        set("armor_prop/con",1);
        set("armor_prop/int",1);
        setup();
}


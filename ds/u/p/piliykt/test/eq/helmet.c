#include <ansi.h>
#include <armor.h>
inherit HEAD;
void create()
{
        set_name(HIC"沖"HIW"雲"HIC"天"NOR,({"sky helmet","helmet"}) );
        set("long",@LONG
相傳是上古時代,后翌所戴的頭盔,聽說戴了可以力大無窮。
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                
                set("unit", "頂");       
                set("value",0);          
                set("volume", 3);                       
                set("material", "ivory");   
        }
        set("armor_prop/armor", 30);
        set("armor_prop/con",20);
        set("armor_prop/str",20);
        set("armor_prop/dix",20);
        set("armor_prop/int",20);
        set("wear_msg",
HIR"$N戴上$n"HIG"之後"HIY"全身的力氣"HIM"忽然變大\n"NOR);
        set("unequip_msg", HIW"$N拿下$n"HIW"後，力氣變小了。\n"NOR);
        setup();
}
int query_autoload() { return 1; }


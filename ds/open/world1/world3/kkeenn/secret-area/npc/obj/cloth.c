#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("空宇之衣", ({ "air cloth","cloth" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件由公家制定的標準小汗衫。\n");
                set("unit", "件");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1200);          
                set("wear_msg", "$N隨手把一件$n披在身上\n");
                set("unequip_msg", "$N汗流浹背, 把$n脫下來曬乾。\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",8);
        setup();
}


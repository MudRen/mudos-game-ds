#include <armor.h>
inherit WAIST;
void create()
{
        set_name("邪惡皮帶", ({ "evil of waist","waist" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一條被邪神碰過的腰帶。\n");
                set("unit", "條");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1150);          
                set("wear_msg", "當$N把$n戴上的那一刻, 你好像看到了地獄?!\n");
                set("equip_msg", "$N的$n被地獄回收了。\n");
           }
        set("armor_prop/dodge",3);
        set("armor_prop/armor",1);
        setup();
}


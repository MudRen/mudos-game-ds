#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIR "祝融面具" NOR ,({ "zhu-rong mask","mask" }) );
        set("long",@long
這是一個刻上祝融火神的金製面具，栩栩如生的祝融神彷彿在面具上
遊動。祝融面具似乎傳來一陣燥熱的感覺，讓你不自禁地流下汗來。
long
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","gold");
                set("unit","張");
                 set("value",2500);
	        set("limit_lv",30);
                set("limit_int",40);
        }
        set("armor_prop/int",2);
        set("armor_prop/armor",8);
          set("armor_prop/shield",20);
        set("armor_prop/wit",1);
        set("armor_prop/bio",-1);
        set("armor_prop/bar",-1);
        setup();
}


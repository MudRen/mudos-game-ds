#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIG"扣雲戒"NOR, ({ "cloud ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","這是王霸從無砂鎮的某一大戶收來的傳家之寶..\n");
                set("unit", "只");
	set("value",10000);
	set_weight(600);
              set("material","jade");
                set("armor_prop/armor", 3);
	 set("armor_prop/int",2);
	 set("armor_prop/con",1);
        }
        setup();
}

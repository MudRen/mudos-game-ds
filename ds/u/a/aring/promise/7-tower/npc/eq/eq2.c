#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIB"白虎"HIY"護腕"NOR, ({ "tiger wrists","wrists" }) );
        set_weight(4000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","千寒山神獸─白虎銀牙的皮所做出的防禦力其佳的護腕。\n");
                set("unit", "雙");
                set("value",5555);
                set("material","silk");
                set("armor_prop/str",2);
                set("armor_prop/int",-1);
                set("armor_prop/shield",10);
                set("armor_prop/armor", 9);
                set("limit_lv",40);
                set("limit_str",50);
                set("limit_con",50);
        }
        setup();
}


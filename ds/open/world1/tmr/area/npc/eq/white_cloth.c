#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("白色布衣",({"white cloth","cloth"}) );
        set("long",@long
一件純白色的布衣，看來手工頗為粗糙，給人一陣安詳的氣味。
long
);
        set_weight(1200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",2);
                set("unit", "件");
                 set("value",2000);
                set("max_lv",50);
                set("limit_lv",25);
                set("armor_prop/int",2);
                set("armor_prop/armor",5);
                set("armor_prop/show_damage",1);
        }
        setup();
}



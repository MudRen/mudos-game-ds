#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("KB衣",({"cloth","cloth"}) );
        set("long",@long
  KOBE所代理的衣服。
long
);
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",2);
                set("unit", "件");
                set("value",100);
                set("max_lv",25);
                set("limit_lv",8);
                set("armor_prop/int",1);
                set("armor_prop/dex",1);
                set("armor_prop/armor",4000);
                set("armor_prop/show_damage",1);
        }
        setup();
}
        int query_autoload() { return 1; }


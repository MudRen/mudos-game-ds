#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name( WHT "黑色緊身衣" NOR ,({"block cloth","cloth"}) );
        set("long",@long
  一件連身的灰黑色緊身衣。
long
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",3);
                set("unit", "件");
                set("value",1);
        }
                set("armor_prop/int",2);
                set("armor_prop/dex",3);
                set("armor_prop/armor",6);
                set("armor_prop/show_damage",1);
        setup();
}

int query_autoload() { return 1; }


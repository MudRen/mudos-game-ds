#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("魔術鞋",({"magic boots","boots"}) );
        set("long","一對得意的魔術鞋，會自動變動大小來適合使用者的腳部。\n");
        set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","對");
set("value",2000);
set("material","cloth");
set("armor_prop/armor", 2);
set("armor_prop/dodge",1);
        }

        setup();
}
int query_autoload() { return 1; }
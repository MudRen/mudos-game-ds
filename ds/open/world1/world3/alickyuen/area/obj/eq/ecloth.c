#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("電子智能衣",({"electric cloth","cloth"}) );
        set("long","這是一件高科技的衣服，會自動調節使用者的體溫。\n");
        set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","件");
  set("value",300);
set("material","cloth");
set("armor_prop/armor", 5);
        }
        setup();
}

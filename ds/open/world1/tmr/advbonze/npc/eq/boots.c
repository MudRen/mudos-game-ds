#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
          set_name("阿羅漢靴" ,({ "a-luo-han boots","boots" }) );
        set("long",@LONG
這是一雙上頭用梵文字寫滿了金剛經文的短靴。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(850);
                  set("unit", "雙");
                set("value",800);
                set("volume",3);
        }
                set("armor_prop/armor", 10);
                set("limit_con",10);
                set("armor_prop/dex", 2);
        setup();
}


#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("羅漢頭盔" ,({ "luo-han helmet","helmet" }) );
        set("long",@LONG
這是一頂純鋼打造的頭盔，上頭竟然還刻了數行的經文。整個頭盔雖
然重了些，但是似乎滿能承受攻擊。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(6000);
                set("unit", "頂");
                set("value",1500);
                set("volume",3);
                set("limit_con",10);
                set("limit_str",10);
        }
                 set("armor_prop/dex", -1);
                 set("armor_prop/str", 2);
                 set("armor_prop/armor", 10);
        setup();
}


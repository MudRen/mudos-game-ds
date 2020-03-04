#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIC"宗本太披風"NOR ,({ "left surcoat","surcoat" }) );
        set("long","這是宗本左左氏家代代相傳的披風，上面寫著「宗本左左太郎」
                    似乎是這件披風最早的主人。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",20);
        set("limit_int",25);
        set_weight(7500);
        set("unit", "件" );
        set("value",3350);
        set("armor_prop/armor", 6);
        set("volume",7);
        set("armor_prop/dex",2);
        set("armor_prop/str",1);
        }
        setup();
}


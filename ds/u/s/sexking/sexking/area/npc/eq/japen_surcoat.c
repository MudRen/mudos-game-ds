#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("日本武士戰袍" ,({ "japen surcoat","surcoat" }) );
        set("long","這是一件日本武士們所披的戰袍，上面有日本國旗的圖案，
                    旁邊還有四個漢字「武士精神」。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",15);
        set_weight(6000);
        set("material", "skin");
        set("unit", "件" );
       set("value",3250);
        set("armor_prop/armor", 8);
        set_temp("apply/damage",6);
                set("volume",5);
        set("armor_prop/con",1);
        }
        setup();
}


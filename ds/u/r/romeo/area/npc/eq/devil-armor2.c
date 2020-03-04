#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;

void create()
{
        set_name(HIB "魔星幻影甲" NOR,({ "devil-armor","armor" }) );
        set("long",
"這是一見透明的戰甲，據說是秦始皇以前出去打戰時所穿的戰甲，\n"
"聽說有一種特別的功用，但是一直都是祕密，並沒有多少人知道，\n"
"在戰甲的四周還有一絲絲的白煙，不知道有什麼用。\n"
);
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "件" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",1600);
        set("replica_ob",__DIR__"devil-armor2");
        set("armor_prop/armor",10);
        set("armor_prop/dex", -6);
        set("armor_prop/con", -10);
        }
        setup();
}

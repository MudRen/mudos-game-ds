#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"飄雲衫"NOR,({"fly cloth","cloth"}) );
        set("long",@LONG
這是一件由雲所編織而成的衣衫，要花費七七四十九年
等待凝結，質感，品質都沒話說。
LONG

);
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("value",240);
        set("armor_prop/armor",15);
        set("armor_prop/dodge",30); 
        set("armor_prop/parry",10);        setup();
}



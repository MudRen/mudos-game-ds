#include <armor.h>
inherit HANDS;
void create()
{
        set_name("畢家護手" ,({ "bi gloves","gloves" }) );
        set("long","這是倚霄一派中畢家家傳的護手，雖然歷年久遠，但末損它的防禦效果。");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "skin");
                set("volume",2);
                set("unit", "雙");
                set("value",2000);
        }
        set("armor_prop/armor",5);
        set("armor_prop/hit",5);
        set("limit_int",20);
        set("limit_level",15);
        setup();
}


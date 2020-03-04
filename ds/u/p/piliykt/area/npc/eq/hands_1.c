#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name(HIR"鳳凰護手"NOR ,({"phoenix hands","hands"}) );
        set("long",@LONG
鳳凰護手,是火鳳凰身上的翅膀尾部,長度大小剛好是可以拿來當護手.
其防禦力高,又輕便.
LONG
);
        set_weight(1800); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_lv",15);
                set("unit", "雙");       
                set("value",3600);          
                set("volume", 6);                       
                set("material", "leather");   
        }
        set("armor_prop/armor",8);       
        set("armor_prop/str",2);
        set("armor_prop/dex",1);     
   setup();
}


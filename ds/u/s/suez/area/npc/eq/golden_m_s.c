#include <armor.h>
inherit PANTS;

void create()
{
set_name("金猿皮",({"Golden monkey skin","skin"}) );
set_weight(2000);
        if( clonep() )
set_default_object(__FILE__);
        else {
set("long",@LONG
    一件閃閃發光的金色毛皮，輕柔的感覺讓你忍不住貼著它磨蹭一般，
但是一貼近這件毛皮，你覺得有股血腥味，而且這股血腥味讓你感到十分
興奮，全身充滿了一種對血的渴望及衝動。
LONG);


set("material", "skin");
set("unit", "張");
set("value", 5000);

set("limit_level",20);
set("armor_prop/armor", 7);
set("armor_prop/shield", 7);
set("armor_prop/str", 2);
set("armor_prop/int", -3);
set("armor_prop/bar", 1);
        }
        setup();
}

#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name(YEL"磁引護手"HIR"(S)"NOR,({ "magnetic wrists","wrists" }) );
        set("long",@LONG
以特殊磁礦製成的一對護手，雖然本身的防禦能力不強，但卻可以將
來襲的兵器斥拒於一旁，補足其防禦力。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(2000);
                set("material", "steel");
                set("unit", "副");
                set("value",3000);
                set("volume",2);
        }
                set("armor_prop/armor", 8);
        setup();
}

int query_autoload() { return 1; }

#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIB"�P�e���Z"HIR"(S)"NOR,({ "galaxy armor","armor" }) );
        set("long",@LONG
�@�Ƥ����W���ݻs���Z�ҡA�Z�ҤW�H�P����m�^�O�L�ƸH�p�A�{�{�o
�G�p�P�m���Ȫe�C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5000);
                set("material", "steel");
                set("unit", "��");
                set("value",3000);
                set("volume",2);
        }
                set("armor_prop/armor", 42);
        setup();
}

int query_autoload() { return 1; }

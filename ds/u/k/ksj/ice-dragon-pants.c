#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(HIW"�B��"HIC"���s��"HIR"(S)"NOR ,({ "ice-dragon pants","pants" }) );
        set("long",@LONG
�H���a�B�諸��´�������ǡA�Ǥl�W´���Q�G���U�ث��A���s�A���R
�����W�C
LONG
);
        set_weight(1300);
        if ( clonep() )
        set_default_object(__FILE__);
        else
        {
         set("material", "leather");
         set("volume",2);
         set("unit", "��");
         set("value",10000);
        }
        set("armor_prop/armor",10);
        setup();
}

int query_autoload() { return 1; }

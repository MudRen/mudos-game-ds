#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name(HIY"�E�_���a"HIR"(S)"NOR,({ "nine-gem crown","crown" }) );
        set("long",@LONG
�^�O�E���_�۪����a�A���b�Y�W�O�Hı�o�L�Q�L��A�_�۪��O�q�i�H
��m�N�O�������C
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
                set("armor_prop/armor", 10);
                set("armor_prop/shield", 6);
        setup();
}

int query_autoload() { return 1; }

#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name(CYN "���H�y�a" NOR ,({ "bird-elephant belt","belt" }) );
        set("long",@LONG
���H���D�Х|�F���@�A�G�Q�K�P�J�����n��C�J�A�ӳo
�O�@���q���H���W���o���y�a�A��a�_���A��o�����C
LONG
);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("volume",1);
                set("unit", "��" );
                set("value", 5000);
        }
         set("armor_prop/armor", 5);
         set("armor_prop/shield", 5);
         set("armor_prop/int", 2);

        setup();
}


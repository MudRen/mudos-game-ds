#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name( CYN "�s�H�@��" NOR ,({ "dragon-elephant wrists","wrists" }) );
        set("long",@LONG
�s�H���D�Х|�F���@�C��G�Q�K�P�J�����F��C�J�A�]��
�զ��s�H�A���F��A��C�A�G�١C��ٻa�s�C�D�й��H�C�s
�@�@�ï��A�H����¡C�ӳo�O�@�ӱq�s�H���W���o���@�áC
LONG
);
        set_weight(5000);
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
         set("armor_prop/str", 2);

        setup();
}


#include <armor.h>
#include <ansi.h>
inherit LEGGING;

void create()
{
        set_name( "�t�H�@��"  ,({ "turtle-elephant leggings","leggings" }) );
        set("long",@LONG
�t�H���D�Х|�F���@�A�G�Q�K�P�J�����_��C�J�A�ӳo
�O�@�ӱq�t�H���W���o���@���A��a��w�A��o�C���C
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
         set("armor_prop/dex", 1);

        setup();
}


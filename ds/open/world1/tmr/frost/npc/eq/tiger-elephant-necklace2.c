#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name( CYN "��H����" NOR,({ "tiger-elephant necklace","necklace" }) );
        set("long",@LONG
��H���D�Х|�F���@�A�G�Q�K�P�J�������C�J�A�ӳo
�O�@���q��H���W���o������A�ⰵ�ե��A���m�ܥءA����
�M���ªZ���N�C
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
           set("armor_prop/con", 2);

        setup();
}


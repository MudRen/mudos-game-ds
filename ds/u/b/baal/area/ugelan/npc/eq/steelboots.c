#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIW"���u" NOR, ({ "steel boots", "boots" }) );
        set("long","�H��ű���A�֦��}�n���m�O���@���u�l�A�O�@��
�h���}�����ˮ`�C\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel" );
                set("unit", "��" );
                set("value" , 1000);
                set("volume",3);
                set("armor_prop/armor", 9);
        }
        setup();
}


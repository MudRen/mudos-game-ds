#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("�K�u", ({ "boots" }) );
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�o�O�@���K�u�l,���q�D�`��,�����m�ܰ�.\n");
                set("unit", "��");
                set("material","iron");
        set("value",2000);
                set("armor_prop/dex",-2);
                set("armor_prop/shield",1);
                set("armor_prop/armor", 16);
        }
        setup();
}


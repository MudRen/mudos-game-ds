#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("�aģ���u", ({ "honor boots","boots" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�o�O�b�Գ��W�ߤF�j�\�A�Ѱ���˦۽礩�A�N��ۺaģ���u�l�C
LONG
);
                set("unit", "��");
                set("material", "silver");
                set("armor_prop/shield", 6);
        }
       setup();
}

#include <armor.h>
#include <ansi2.h>

inherit CLOTH;

void create()
{
        set_name(HIR"��ĦЦ�"NOR, ({ "phoenix leather", "leather" }));
        set_weight(200);
        set("long", @long
�o�@��O�ѻ�Ĩ��W���Ф�һs������A�A���_�îa�s���A
�㦳�����W���\�ġC
long);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "leather");
                set("armor_prop/armor", -100 );
                set("armor_prop/shield", -100 );
                set("armor_prop/damage", -100 );
        }
        setup();
}


#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("���Ѿc", ({ "flying shoes","shoes" }) );
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"�ܻ��ܻ����c�l�A�u�n�A���\���n�A�����@�D�N��N���G�E\n");
                set("unit", "��");
                set("material", "fur"); 
                set("value",1400);                set("armor_prop/shield",9);
                set("armor_prop/armor",9); 
                set("armor_prop/dex",1);
        }
        setup();
}


#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("�Ф�ܭ�", ({ "feather surcoat", "surcoat" }) );
        set("long",
                "�o�O�@��ΦФ�s�����ܭ�, ���M�D�`����, ���O���m�O�]���a�C\n");
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  7);
                set("limit_dex",10);
                set("value", 400);
                set("armor_prop/dex", 1);
                set("material", "silk");
        }
        setup();
}



#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name("�Ф��@��", ({ "bird wrists", "wrists" }) );
        set("long",
                "�o�O�@��ΦФ�s�����@��, ���M�D�`����, ���O���m�O�]���a�C\n");
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor",  4);
                set("limit_dex",10);
                set("armor_prop/dex", 1);
                set("material", "silk");
        }
        setup();
}


#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"����"HIC"�ܭ�"NOR ,({ "cloud surcoat","surcoat" }) );
        set("long","�o�O�@�����ƪ��ܭ�, ���M����, ���O���m�O�o�ܰ�,
��O�ܦn���@��F�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1500);
        set("value", 8000);
        set("unit", "��" );
        set("material", "silk");
        }
        set("armor_prop/armor", 15);
        set("armor_prop/dex", 2);
        set("limit_dex",25);
        setup();
}


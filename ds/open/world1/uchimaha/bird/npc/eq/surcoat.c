#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"����"HIC"�ܭ�"NOR ,({ "blue_surcoat","surcoat" }) );
        set("long","�o�O�@�����ƪ��ܭ�, ���M����, ���O���m�O�o�ܰ�,
��O�ܦn���@��F, �i�O�n���ܰ����t�פ~��ޱ��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1500);
        set("material", "surcoat");
        set("unit", "��" );
        set("armor_prop/armor", 15);
        set("armor_prop/dex", 2);
        set("limit_dex",25);
        set("material", "silk");
        }
        setup();
}

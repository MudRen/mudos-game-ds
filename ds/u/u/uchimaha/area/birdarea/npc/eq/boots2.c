#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIW"����"HIC"�Źu"NOR, ({ "cloud boots", "boots"  }) );
        set("long","�o�O�@�������ƪ����u, ���M����, ���O���m�O�o�ܰ�,
��O�ܦn���@��F�C\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value", 1500);
                set("armor_prop/armor",  12);
                set("armor_prop/shield",  10);
                set("armor_prop/dex", 2);
                set("limit_dex",25);
                set("material", "silk");
        }
        setup();
}

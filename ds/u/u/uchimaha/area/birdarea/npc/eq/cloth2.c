#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"����"HIC"�ŭm"NOR, ({ "cloud cloth", "cloth"  }) );
        set("long","�o�O�@�����ƪ���m�A���M�ܻ����A���O���m�O�o�ܰ��A
��O���o�@�����@��F�C\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value",4000);
                set("armor_prop/armor",  20);
                set("armor_prop/shield",  10);
                set("armor_prop/dex", 2);
                set("limit_dex",30);
                set("limit_level",30);
                set("material", "cloth");
                set("armor_prop/show_damage",1);
        }
        setup();
}



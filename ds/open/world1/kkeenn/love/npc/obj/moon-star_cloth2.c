#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( "�H�벨�P" , ({ "moon-star cloth", "cloth"  }) );
        set("long","�o�O�@��H�����W�Y�v�s´�Ӧ����k�ʦ�n�A�u������m�ܥءA\n"
                   "���R��_�A�����O�H�������C\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value", 8000);
                set("material", "cloth");
        }
        set("armor_prop/armor",  10);
        set("armor_prop/shield",  10);
        set("armor_prop/int", 1);
        set("armor_prop/dex", 2);
        set("female_only",1);
        setup();
}


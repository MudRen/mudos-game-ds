#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(CYN"�������"NOR,({"huge armor","armor"}) );
        set("long",@LONG
�o�O�@��s�@���׷�������ҡA���Ʊ���m�����ۥ���s´�Ӧ��C 
�o��O���԰��ӧ@���E
LONG);
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��");
        }
        set("value",1800);
        set("limit_lv",25); 
        set("limit_race","���~");
        set("armor_prop/armor",39);
        set("armor_prop/shield",13); 
        set("armor_prop/con",2);
        set("armor_prop/dex",-2);
        setup();
}


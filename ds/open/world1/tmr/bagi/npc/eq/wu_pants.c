#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
        set_name(HIY "�H���~���" NOR ,({ "freeze-sun pants","pants" }) );
        set("long",@LONG
�o�O�@��ѤK���T�a���u�@�~�u�H��v���Ʀ��v�s´�Ӧ�����ǡC    
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",1200);
        }
        set("armor_prop/armor",8);
        set("armor_prop/int",1);
        set("armor_prop/con",1);
        setup();
}

// cloth.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
set_name(HIB"�C���"NOR,({"blue clothes","clothes"}));
set("long", @LONG
�o�O����ѳ\�h�C������ҽs´�����@���A, ���m�O���G�����C
LONG);
set_weight(3900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",6300+random(700));
set("limit_lv",34);
set("material", "cloth");
//set("armor_prop/armor",78);
//set("armor_prop/defense",1);
}
        setup();
}



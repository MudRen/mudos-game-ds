#include <armor.h>

inherit ARMOR;
void create()
{
        set_name("�Ϥ�n�Z��", ({ "gambeson armor","armor" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long","�@��㦳�Ϥ�Ũ�̪��Z�ҡA��_�Ӥ����W�j�F���m�O�A�]�U�ΤF�ΪA�C\n");
        set("unit","��");
        set("value",0);
        set_weight(12340);
        set("material","leather");
        set("armor_prop/armor",40);
        set("armor_prop/con",2);
        }
        setup();
}


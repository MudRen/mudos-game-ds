#include <armor.h>

inherit WAIST;

void create()
{
        set_name("�]����",({"mist jade","jade"}) );
        set("long","�@�T�Υե��J�Z�Ӧ����ɨءA�W�Y�٨観�����`�s�������C\n");
        set_weight(200);
        set("unit","�T");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�T");
                set("value",500);           
                set("material","jade");
                set("armor_prop/armor",4);
        }
        setup();
}


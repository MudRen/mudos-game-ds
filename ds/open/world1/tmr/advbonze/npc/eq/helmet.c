#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("ù�~�Y��" ,({ "luo-han helmet","helmet" }) );
        set("long",@LONG
�o�O�@���¿����y���Y���A�W�Y���M�٨�F�Ʀ檺�g��C����Y����
�M���F�ǡA���O���G����Ө������C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(6000);
                set("unit", "��");
                set("value",1500);
                set("volume",3);
                set("limit_con",10);
                set("limit_str",10);
        }
                 set("armor_prop/dex", -1);
                 set("armor_prop/str", 2);
                 set("armor_prop/armor", 10);
        setup();
}


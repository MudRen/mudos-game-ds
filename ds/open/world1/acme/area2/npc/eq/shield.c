#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name("���Y��" ,({ "ghost head shield","shield" }) );
        set("long","�o�O�@�Ӧ��۰����Y���˪��j�ޡC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(1500);
        set("material", "iron");
        set("unit", "��" );
       set("value",2300);
        set("volume",3);
        }
        set("armor_prop/armor", 15);
        set("armor_prop/con",2);
         set("limit_str",10);
        setup();
}


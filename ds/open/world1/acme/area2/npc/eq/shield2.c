#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name("�����Ȭ�" ,({ "water shield","shield" }) );
        set("long","�o�O���Z���@�k���@�����N�Ҹ˳ƪ��ȬޡC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(10000);
        set("limit_str",10);
        set("material", "silver");
        set("unit", "��" );
       set("value",2250);
        set_temp("apply/hit", -4);
        set_temp("apply/armor", 15);
		set("volume",2);
        set("armor_prop/dex",-2);
        }
        setup();
}

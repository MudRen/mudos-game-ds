#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�����Ԧ�", ({ "DeadGod","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�Z�L���H�@���Q�n���Ԧ�A�@�W�u���@��C\n");
                set("unit", "��");
                set("material", "cloth");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",20000);
                set("armor_prop/parry",1);
                set("armor_prop/armor",5);
        }
        setup();
}
int query_autoload() { return 1; }

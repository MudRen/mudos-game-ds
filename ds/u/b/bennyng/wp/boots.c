#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("�����B�ʾc", ({ "DeadGod","boots" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o���B�ʾc�ܻ�,�n���S��@�ˡC\n");
                set("unit", "��");
                set("material", "cloth");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",25000);
                set("armor_prop/dex",5);
                set("armor_prop/dodge",5);
                set("armor_prop/armor", 2);
        }
        setup();
}
int query_autoload() { return 1; }

#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"�Z�h�ܭ�"NOR ,({ "Jedi Surcoat","surcoat" }) );
        set("long","�o�O�@��"HIW"�yJedi Knight�z"NOR"�M�Ϊ��ܭ��C\n");
set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "surcoat");
        set("unit", "��" );
        set("no_sac",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_sell",1);
          set("armor_prop/armor", 20);
          set("armor_prop/con", 5);
        }
        setup();
}
int query_autoload() { return 1; }

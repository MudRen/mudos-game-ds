#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIG"�p��z"HIC"�M���@��"NOR ,({ "mulder wrists","wrists" }) );
        set("long","�o�O�@�Ӥp��z�M�Ϊ�����C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "wrists");
        set("unit", "��" );
	set("no_sac",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_sell",1);
        set("value",300);
        }
         set("armor_prop/armor", 100);
         set("armor_prop/con", 10);
         set("armor_prop/dex", 10);
         set("armor_prop/shield", 100);
         set("armor_prop/int", 10);
        setup();
}
int query_autoload() { return 1; }
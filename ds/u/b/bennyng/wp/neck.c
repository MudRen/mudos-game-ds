#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name("��������", ({ "DeadGod","necklace" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�x�_�®𪺪k�N�V��,\n"
                           "��k�N����ܤO���۷��¤O,���۷����m�O�C\n");
                set("unit", "��");
                set("material", "carbon");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",40000);
                set("armor_prop/wit",5);
                set("armor_prop/sou",3);
                set("armor_prop/int",3);
                set("armor_prop/shield",20);
                set("armor_prop/armor", 3);
        }
        setup();
}
int query_autoload() { return 1; }

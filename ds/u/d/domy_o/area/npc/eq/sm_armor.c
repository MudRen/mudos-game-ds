#include <weapon.h>
#include <ansi.h>

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
set_name(MAG"�iSM�M�Ρj"HIW"�Z��"NOR,({"sm armor","armor"}) );
set("long","�o�O�@��SM�M�Ϊ��`������ˡA���H���Ī��n�F��C\n");
set_weight(3100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "armor");
set("unit", "��");
set("value",1500);

set("wield_wear","$N��W$n�H��A�Kı�o�ۤv�ܩʷP\n");

set("armor_prop/armor", 10);
set("armor_prop/shield", 3);

        }
        setup();
}


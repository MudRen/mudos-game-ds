#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(MAG"��]"HIW"��"BLU"�Q�r�Y"NOR, ({ "night hands","hands" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","�o�Ӥp�p���Y�l�A���M���_���A���O�R���F�]������C\n");
        set("unit", "��");
        set("material", "cloth");
        set("no_drop",1);
	set("no_sell",1);
        }
        set("armor_prop/wit",2);
        set("armor_prop/bio",1);
        set("armor_prop/bar",1);
        set("armor_prop/int",10);
        set("armor_prop/shield",25);
        set("armor_prop/show_damage",1);
        setup();
}

int query_autoload() { return 1; }

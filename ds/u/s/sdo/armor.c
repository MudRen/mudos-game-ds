#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(MAG"��]"HIW"��"BLU"�ԥ�"NOR, ({ "night armor","armor" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
        set("long",@LONG
�o��ԥҬO�]�����]���M�ξԥҡC���M���b��W�Pı�ܻ��A���L���@
���v�T������ΩʡC�o�O�]����������O�@�ؤQ���S���X���A�ǻ�
���o�ئX���u���ѯ�����ϥΡC
LONG
	);
        set("unit", "��");
        set("material","steel");
        set("value",1);
	set("no_sell",1);
	set("no_drop",1);
        }
          set("armor_prop/con",25);
        set("armor_prop/int",5);
        set("armor_prop/dodge",5);
        set("armor_prop/shield",20);
        set("armor_prop/armor",100);
        setup();
}

int query_autoload() { return 1; }

void init()
{
	if( environment(this_object()) == this_player() )
	this_player()->set_temp("has_light",1);
}

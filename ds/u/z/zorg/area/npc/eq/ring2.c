#include <path.h>
#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
	set_name(HIC"��q�٤l"NOR,({"pwoerful ring","ring"}));

	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",HIB"�o�O�@�T���M�`���٤l�A�ݨӳo�٤l���@�ǯS�O���B�C\n"NOR);	    
                	set("unit", "�T");
		set("value",4000);
         		set("material", "starring");
		set("armor_prop/armor", 10);
		set("limit_str",32);
		set("armor_prop/int",5);
	}
	set("wield_msg","$N�q�U�̮��X$N���b��W�I\n");
	set("unwield_msg", "$N�N�⤤��$n�p�ߦ��n�C\n");
	setup();
}

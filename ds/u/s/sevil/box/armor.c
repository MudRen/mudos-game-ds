#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"�����Z��"NOR ,({ "evil armor","armor" }) );
        set("long",@LONG
        
    �o�O���J���F�L���@�ö��A�ϥαj�j���]�O�һs�y�X�ӡC�ѩ��ĭ���j�j��
�]�O�A�]���i��m�j�O�������A�O�@��֦�������C
LONG
);
        set_weight(100);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
        	set("material", "skin");
        	set("unit", "��");
		set("volume",6);
        	set("limit_con",8);
        	set("value",7345);
	}
	set("no_sac",1);
        setup();
        set("armor_prop/armor",100);
        set("armor_prop/shield",50);
}


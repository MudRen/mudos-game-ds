#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"�չ��֦�"NOR ,({ "white fur cloth","cloth" }) );
        set("long",@LONG
        
  �o�O�ѹ������զ��ְ��s�����֤j��A�֦�W���\�h�������n��
�A�ѩ��u�ʷ��ΡA���Y�O�ܦn�A�ҥH�Y���髬�S���H�]�i�H����
��W�C�X�n����֥i�H�l���j�����������O�A�ѩ󹫯����X���S�A�O
�@��ǻ���������C
        
LONG
);
        set_weight(8900);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
        	set("material", "skin");
        	set("unit", "��");
        	set("limit_con",6);
        	set("value",8260);
	}
	set("no_sac",1);
	set("monster_armor_type","armor");
	set("monster_armor_prop/dex",2);
	set("monster_armor_prop/int",-1);
	set("monster_armor_prop/armor",19);
	set("monster_armor_prop/shield",8);
	set("armor_prop/dex",2);
	set("armor_prop/int",-1);
	set("armor_prop/armor",19);
	set("armor_prop/shield",8);
        setup();
}

int query_autoload() { return 1; }
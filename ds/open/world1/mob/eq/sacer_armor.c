#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"���l�n�֥�"NOR ,({ "yeah chuay armor","armor" }) );
        set("long",@LONG
        
  �o�O���]�~���l���p�ְ��s�����p���֥�, �֥ҤW���\�h�T�\����
�w�����, �ѩ��u�ʷ���, ���Y�O�ܦn, �ҥH�Y���髬�S���H�]
�i�H������W�C�X�n���p�֥i�H�l���j�����������O, �ѩ���o��k
�Q���x��, �O�@��ǻ���������C
        
LONG
);
        set_weight(8800);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
        	set("material", "leather");
        	set("unit", "��");
        	set("limit_con",8);
	}
	set("value",7345);
	set("volume",6);
	set("no_sac",1);
	set("monster_armor_type",TYPE_ARMOR);
	set("monster_armor_prop/con",2);
	set("monster_armor_prop/armor",42);
	set("monster_armor_prop/shield",18);
	set("monster_armor_prop/dodge",-4);
	
	set("armor_prop/dex",-3);
	set("armor_prop/con",2);
	set("armor_prop/armor",36);
	set("armor_prop/shield",8);
        setup();
}


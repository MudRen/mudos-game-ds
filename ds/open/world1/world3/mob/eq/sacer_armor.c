#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"���l�n�֥�"NOR ,({ "yeah chuya armor","armor" }) );
        set("long",@LONG
        
  �o�O���]�~���l���p�ְ��s�����p���֥�, �֥ҤW���\�h�T�\����
�w�����, �ѩ��u�ʷ���, ���Y�O�ܦn, �ҥH�Y���髬�S���H�]
�i�H������W�C�X�n���p�֥i�H�l���j�����������O, �ѩ���o��k
�Q���x��, �O�@��ǻ���������C
        
LONG
);
        set_weight(13800);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
        	set("material", "skin");
        	set("unit", "��");
        	set("limit_con",8);
        	set("value",7345);
	}
	set("no_sac",1);
	set("armor_prop/dex",-1);
	set("armor_prop/con",2);
	set("armor_prop/armor",28);
	set("armor_prop/shield",8);
        setup();
}

int query_autoload() { return 1; }
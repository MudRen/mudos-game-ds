#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name(HIB"�K���ťO"NOR, ({ "eight necklace","necklace" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","�o�Ӥp�p���K���ťO, �b���`�H���̥u���X�����@��,\n"
                           "���o�g�L�S�O�[���L���ťO, �o�i�H���ɹ�k�N�����m�O�C\n");
		set("unit", "��");
		set("material", "cloth");
		set("needaward",35);
	set("value",1);
	}
	set("armor_prop/wit",2);
	set("armor_prop/bio",-1);
	set("armor_prop/bar",-1);
	set("armor_prop/int",5);
	set("armor_prop/shield",25);
	setup();
}

int query_autoload() { return 1; }

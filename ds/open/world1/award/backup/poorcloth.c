#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("�S�s�֥�", ({ "special leather armor","armor" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��֥Ҭ�b���W, �����F��������ê, ��O�_�s�o\n"
                           "�ܦn���@��֥�, ���O�o�֥ҬO�t�Ŧ⪺, �ݨӻ�ǲ��C\n");
	set("value",1);
		set("unit", "��");
		set("material", "leather");
		set("needaward",15);
	}
	set("armor_prop/parry",12);
	set("armor_prop/armor",20);
	set("armor_prop/shield",15);
	set("armor_prop/bio",-1);
	set("armor_prop/wit",1);
	setup();
}

int query_autoload() { return 1; }

#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
	set_name(HBK"���ܭ�"NOR,({"dark moon cloak","cloak"}) );
	set("long",@LONG
�o�O�@��¦⪺���ܭ��A�ܭ��W��¸�F�@�ӷs��μлx�C�ڻ��o
��ܭ��O�H�e���Ъ���Ф��_�A��������y�����B�C�o��ܭ�����
�l�����u���O�q�A�i�H���˳ƪ̪���m�����Q�ĤH�ҵo�{�C
[�i�x�s�˳�]
LONG
);
	set_weight(9200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "��");
		set("limit_con",3);
        	//set("no_sell",1);
		set("no_sac",1);
		set("armor_prop/dodge", 14);
		set("armor_prop/armor", 18);
		set("armor_prop/shield",21);
        }
	set("wear_msg",HBK"$N"HBK"�N�@��$n"HBK"�ܦb���W, ��ӤH�ϩ��Ƭ��@���¼v!!\n"NOR);
	set("unequip_msg",HBK"$N"HBK"�N$n"HBK"�ѪӤW���U, �@�}�¼v���������C\n"NOR);
	set("value",12215);
        setup();
}

int query_autoload() { return 1; }
#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
	set_name("�P��ܭ�",({"sun cloak","cloak"}) );
	set("long",@LONG
�o�O�@����⪺���ܭ��A�ܭ��W��¸�F�@�ӤӶ����ϮסC�ڻ��o
��ܭ��i�H�X���H��A��������y�����B�C��������i�H���˳ƪ�
����۷������O�@�C
LONG
);
    set_weight(2680);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "skin");
		set("unit", "��");
		set("limit_con",3);
        	//set("no_sell",1);
		set("no_sac",1);
		set("armor_prop/fire", 10); //���t����.
		set("armor_prop/armor", 9);
		set("armor_prop/shield",12);
        }
	set("wear_msg",HBK"$N"HBK"�N�@��$n"HBK"�ܦb���W, ��ӤH�ϩ��Ƭ��@���¼v!!\n"NOR);
	set("unequip_msg",HBK"$N"HBK"�N$n"HBK"�ѪӤW���U, �@�}�¼v���������C\n"NOR);
       set("add_value",2870);
	set("value",3215);
        setup();
}


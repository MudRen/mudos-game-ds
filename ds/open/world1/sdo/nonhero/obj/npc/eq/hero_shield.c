#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(HIC"�^������"NOR,({"hero shield","shield"}));
        set_weight(4000);
        if( clonep() )
		set_default_object(__FILE__);
        else 
	{
        set("unit", "��");
        set("volume",5);
        set("long", @LONG
�o����y�޵P�i�O���۵L�W�^���X�ͤJ���A���U�L�L�Ʀ��b��n���Y
�צ�ĤH���P�R�������C�ѩ��즳�g�L���H���B�z�A�ҥH���W�G�`
�H�Q�������m�O�C
LONG
	);
       	set("value",2000);
        set("material","wood");
        }
        set("armor_prop/armor",25);
        setup();
}
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�P��ԪA" ,({ "sun cloth","cloth" }) );
        set("long",@LONG
�@�ݴN���D�o���O�@�󴶳q����A�C�����⪺���ƺN�_��
�N���O�K���몺���A�S�t��¸�������⪺��A�ݰ_�ӤQ����
�m���C
[�i�x�s�˳�]
LONG
);
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        	set("material", "cloth");
        	set("unit", "��" );
		set("no_sac",1);
	}
	set("value",3280);
	set("armor_prop/fire", 8); //���t����.
	set("armor_prop/armor", 13);
	set("armor_prop/unarmed", 5);
	set("armor_prop/combat", 5);
	set("armor_prop/shield",8);
        setup();
}
int query_autoload() { return 1; }

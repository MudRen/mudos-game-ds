#include <armor.h>
inherit WAIST;

void create()
{
	set_name("�y�a",({"belt"}));
	set("long",@LONG
�o������O�ѳ\�h�����R�[���]�Ҧꦨ���A��{�b����o�ج��R���]�l
�w�g�ܤ֤H�|���F�C
LONG
	);
	set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "��");
	}
	set("auto_set",2);
	setup();
}
// int query_autoload() { return 1; }


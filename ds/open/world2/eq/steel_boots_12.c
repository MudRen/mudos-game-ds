#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�Ѣٿ��u",({"ck steel shoes","shoes"}) );
	set("long",@LONG
�o���I�������u�O�饻���Ѣ٭������X�U�ħL�Ωҳ]�p���A���]����
�`�B���岫�A�w�g�����^���F�C
LONG
);
	set_weight(5950);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
	set("value",2450);
	set("armor_prop/armor", 12);
	setup();
	set("volume", 4);
}

//int query_autoload() { return 1; }

#include <weapon.h>
inherit FIST;
void create()
{
	set_name("��s����",({"wood finger","finger"}));
	set("long",@LONG
�o���s����Q�����աA�����G������T�A�@�륭�ɮ��ӽm��
���k�έˤQ���X�A�C

LONG
);
	set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","wood");
	}
	set("value",280);
	init_fist(13);
        setup();
}

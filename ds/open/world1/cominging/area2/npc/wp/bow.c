#include <ansi.h>
#include <weapon.h>
inherit BOW;

void create()
{
	set_name(HIG"���L�}"NOR,({"green bow","bow"}));
	set_weight(9500);
        if( clonep() )
		set_default_object(__FILE__);
        else {
        	set("long","�o�O�@��Τ��Y�Ұ����}�A�W������ӵo�f�A�n���ܨI�����ˤl�A���κ�⪺���������A�n���㦳���_���k�O�@��C\n");
		set("unit", "��");
		set("value", 2230);
		set("rigidity", 300);    // �w��
		set("material","iron");
		set("limit_str", 4);
		set("weapon_prop/dex",-1);
	}
	init_bow(10);   // �׷i�ˮ`�O = set("weapon_prop/damage", 14);
	setup();
}
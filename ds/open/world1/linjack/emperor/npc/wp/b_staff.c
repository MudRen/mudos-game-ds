#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("���M��", ({ "bladed staff","staff" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��D�`�D�`�֨����M��, ����b���Aı�o�o��M��,\n"
                            "�M�j�M��b�S��������O, ���L�ϰ_�o�M���٬O�Χ��k�����\n"
                            "��, �ӥB�o�M�����M�b�٬۷���, �p�G���U�ε��c���D, �o\n"
                            "�M�����H���}�a�O���O�۷���H���C\n");
		set("value", 2500);
		set("material","steel");
                set("limit_con",20);
		set("limit_str",35);
		set("limit_staff",60);
	}
    set("weapon_prop/dex",-1);
    set("weapon_prop/con",1);
	init_staff(65,TWO_HANDED);
    setup();
}

#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("���b�M", ({ "double blade","blade" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��u�������b�M, �Ҽ˦��M, ���O��꦳��b,\n"
                            "�L���Ǥ�, ��b���M���b���C, ���M�A�i�H�⥦��C��, \n"
                            "���O���M���S���٬O�H�M�k���D�y, �Q�H�C�N�Ϧ��M, �D\n"
                            "�`�e���˨�ۨ�. ���M�ݭn�۷��q���M�k�M�ӱ��~�i��\n"
                            "�ΡC\n");
		set("value", 2500);
		set("material","steel");
		set("limit_skill",75);
		set("limit_dex",40);
	}
    set("weapon_prop/hit",20);
    init_blade(55);
    setup();
}

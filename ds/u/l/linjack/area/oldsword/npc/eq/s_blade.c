#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name("�����C�a��", ({ "special blade","blade" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��M�M�@����M�D�Ϊ̨ϥΪ����M�õL���, ���L�J��\n"
                            "�[�ݫK�|�o�{, ���M���M�b���e�B�w, �M�P�p��, ��b�����o\n"
			    "�ش��L�Q�𪺤M, �p��ٱo�W�O�@���_�M?\n");
		set("value", 18000);
		set("material", "steel");
		set("limit_skill",40);
		set("limit_dex",30);
		set("limit_int",15);
		set("replica_ob",__DIR__"bigblade.c");
        }
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",1);
    set("weapon_prop/bio",-1);
    set("weapon_prop/tec",-1);
    set("weapon_prop/hit",8);
    init_blade(45);
    setup();
}

#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("���b���", ({ "broad axe","axe" }) );
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�`���Y���k������b, �ӥB�y���٦��@�ڵu�@, ���q����, �Q�n\n"
                            "��⮳�_�����G���ӥi��, ���L���ⴧ�R������Ī��¤O�Q����H�C\n");
		set("value", 2500);
		set("material", "steel");
		set("limit_skill",30);
		set("limit_str",40);
		set("limit_con",15);
        }
    set("weapon_prop/dex",-2);
    set("weapon_prop/hit",-15);
    init_blade(50,TWO_HANDED);
    setup();
}

#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name("�մ������", ({ "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o������O�H���ťմ���һs��, ��a��w, �p��@��, \n"
                            "�b�����H�ɦ��۷��ˮ`�O�C\n");
		set("value", 3000);
		set("material", "wood");
		set("limit_skill",30);
		set("limit_str",25);
		set("limit_con",15);
        }
    init_staff(35);
    setup();
}

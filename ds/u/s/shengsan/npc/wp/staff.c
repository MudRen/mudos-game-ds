#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(HIC"�l�P�k��"NOR,({"staff"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�o�O�@��ΨӼ��ۨ����Ϊ�����A�ר䨫�s���ɯS�O�n�ΡC\n");
               set("material", "wood");
        }
	init_staff();
	setup();
}

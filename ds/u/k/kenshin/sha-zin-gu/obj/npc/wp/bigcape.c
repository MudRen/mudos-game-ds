#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIW"�k�Ѵ�"NOR, ({ "fa-tian cape","cape" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�v�騦���v�ũҥ��y���ҡA���ҾW�Q�A���O�l�D�����A�ҥH�u�A�X��ߤ����ұM�ΡC\n");
                set("value", 2000);
                set("material", "steel"); 
                }
        init_staff(30);
        set("weapon_prop/bio", 1);
                setup();
}


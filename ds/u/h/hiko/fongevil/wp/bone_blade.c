#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name("�_���M", ({ "bone blade","blade" }) );
        set_weight(5500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��i�H�A���_�����M, �O�ݩ󤿴ݤ��H���̷R\n");
                set("material", "iron");
                set("value",4000);
                set("volume",4);
             }
        set("weapon_prop/str",2);
        set("weapon_prop/con",1);
        init_blade(60,TWO_HANDED);
        setup();
}


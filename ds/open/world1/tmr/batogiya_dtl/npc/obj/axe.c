#include <weapon.h>

inherit F_AXE;

void create()
{
    set_name("���ɭ鸨��", ({ "ha lipoluo axe", "axe" }) );
    set_weight(2000);
    setup_axe(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"axe"}));
        set("unit", "��");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "�@�⫢�����S�s���u��A�W�Y�٨�e�ۤ@�ӯ��y�A�Q������C\n");
    }
    setup();
}

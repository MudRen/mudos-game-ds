#include <weapon.h>

inherit F_BLADE;

void create()
{
    set_name("���ɭ鸨�M", ({ "ha lipoluo blade", "blade" }) );
    set_weight(2000);
    setup_blade(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"blade"}));
        set("unit", "��");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "�@�⫢�����S�s���u�M�A�W�Y�٨�e�ۤ@�ӯ��y�A�Q������C\n");
    }
    setup();
}

#include <weapon.h>

inherit F_DAGGER;

void create()
{
    set_name("���ɭ鸨�P", ({ "ha lipoluo dagger", "dagger" }) );
    set_weight(2000);
    setup_dagger(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"dagger"}));
        set("unit", "��");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "�@�⫢�����S�s���u�P�A�W�Y�٨�e�ۤ@�ӯ��y�A�Q������C\n");
    }
    setup();
}

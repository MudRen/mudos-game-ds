#include <weapon.h>

inherit F_SWORD;

void create()
{
    set_name("���ɭ鸨�C", ({ "ha lipoluo sword", "sword" }) );
    set_weight(2000);
    setup_sword(3, 10, 80, 1);

    if( !clonep() ) {
        set("wield_as", ({"sword"}));
        set("unit", "��");
        set("value", 1000);
        set("rigidity", 10);
        set("long", "�@�⫢�����S�s���u�C�A�W�Y�٨�e�ۤ@�ӯ��y�A�Q������C\n");
    }
    setup();
}

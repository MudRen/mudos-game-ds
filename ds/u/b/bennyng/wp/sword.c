#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("���������C", ({ "DeadGod sword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@�ⴲ�o�����C�𪺾W�Q���C,�A���T���Ͳ��𪺷Pı,\n"
                            "�O�@��ѤU�L�����_�C,�O�������M�ΪZ���C\n");
                set("value", 95000);
//              set("no_drop",1);
                set("no_sac",1);
                set("material", "steel");
        }
    set("weapon_prop/str",3);
    set("weapon_prop/parry",10);
    set("weapon_prop/hit",5);
    set("weapon_prop/bio",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/tec",1);
    set("weapon_prop/wit",1);
    set("weapon_prop/sou",1);
    init_sword(10);
    setup();
}
int query_autoload() { return 1; }

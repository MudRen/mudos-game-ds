#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIR"�t��"HIY"���s�C"NOR, ({ "flame turn-dragon sword","sword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","��Ӹt�������ðΪ��F��A�N�O�o��C�A�ӳo��C��Ӥ@���æb\n"
                           "���s������̡A���Ǥd�ʦ~�ӡA�L�H����C\n");
                set("value",30000);
                set("volume",5);
        }
    set("weapon_prop/str",3);
        set("weapon_prop/dex",-2);
    set("weapon_prop/hit",10); 
    set("weapon_prop/bar",1);
    set("weapon_prop/tec",1);
        init_sword(65+this_player()->query("level")/5);
    setup();
}


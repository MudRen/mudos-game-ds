#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(MAG"���Y�s"RED"�@����"NOR, ({"dark amulet","amulet" }) );
        set("long", "�o�O�@�Ө観�·t���Z��J�起���O�����Y�s�@���šC\n");
        set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor", 300);
                set("armor_prop/shield", 600);
        set("wear_msg",CYN"$N"CYN"�N�@��$n"CYN"���b��l�W, �C�n������g�|�·t���Z��ë��C\n"NOR);
        set("unequip_msg",CYN"$N"CYN"�N$n"CYN"�Ѳ�l�W���U, ���n���g���·t���Z���j�j�C\n"NOR);
                set("value", 20000);
        }
        setup();
}

int query_autoload() { return 1; }

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�����y�N"NOR,({"eagle of fire","eagle","fire"}));
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED"�o�O�@���y�N�Ϊ������������A�Y�ϤW���g�W�F�d�g�A���M���@��\n"
                            "��䯫�����𮧡C�i�ͱ��_���y�N�������������G�����ۧA�C�A��\n"
                            "����ı�����Ҧ��Ұg�b�A�Pı���J�F�@�إȤ۪��ŵꤧ���C\n"NOR);
                set("value", 0);
                set("no_sell",1);
        }
        setup();
}



#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit HAMMER;

void create()
{
        set_name(HIC"�����l" NOR,({"jur hie hammer","jur","hie","hammer"}) );
        set("long",
        "�o�O�@�����۷������j�l�A�l�����۲H�ť��~\n"
        "�o��lť���O�����b���Ѭݨ�����{�{�ť��A�]��\n"
        "���J�䤤�M�V�ӥѮɡA�ҵo�U�쪺�Ŵ��һs���A��\n"
        "�l�O��ѷ�ɮȩ~�y���������K�v�Ű����A�¤O�Q\n"
        "���j�j�A�@�W�õL�X�i�����C\n"
        );
        set_weight(8000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",14000);
                set("limit_str",20);
                set("limit_con",30);
                set("volume",3);
                set("limit_int",10);
                set("limit_dex",5);
                set("limit_skill",70);
        }
   set("weapon_prop/hit",7);
   set("weapon_prop/str",3);
   set("weapon_prop/dodge",7);
   init_hammer(55);
        setup();        
}



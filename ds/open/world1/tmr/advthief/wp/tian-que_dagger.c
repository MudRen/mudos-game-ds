#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("�ѯʤP",({"tian-que dagger","dagger"}) );
        set("long",@LONG
�o�O�ѤU�Ĥ@�s��-��ӺD�Ϊ��P���A��y�Ϊᥩ�A���ܤѦa�y�Ƥ�
�u�A�ȥզ⪺�P�W�a�ۤ@�����Ŧ⪺�����C
LONG
);
         set_weight(2500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",5000);
        }
        set("weapon_prop/dex",1);
        set("weapon_prop/str",1);
        set("limit_level",25);
        set("limit_dex",50);
        init_dagger(45);
        set("backstab_bonus",40); //�ʤ���
        setup();        
}


//�o�O�[�j��....wiz��

#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
        set_name(HIR"�U�N����"NOR,({"burning hands","hands","hand","fist"}) );
        set ("long", @LONG
�o�O�@�����⪺��M�A�����o�X��������A���H���طq�Ȫ�
�Pı�C�ڻ��o�O300�~�����@�쨸�c���k�v�b����M�W���]�j
�j���G��A�㦳�������·t�O�q�C
LONG
);
        set_weight(20);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",0);
        set("material","fur");
        set("no_drop",1);
        }

        set("weapon_prop/bio",12);
        set("weapon_prop/bar",12);
       set("weapon_prop/wit",6);
        set("weapon_prop/sou",6);
        set("weapon_prop/str",6);
        set("weapon_prop/con",6);
init_fist(300);
        setup();
set("wield_msg", HIR"$N�w�w���W�@��$n"HIR"�A���M�@�}����q$N"HIR"��ߩb�˥X�ӡA�O�H�h�o�C\n"NOR);
}
int query_autoload() { return 1; }

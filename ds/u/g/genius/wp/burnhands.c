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
        set_weight(1000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",3500);
        set("material","fur");
        set("no_drop",1);
        }

        set("weapon_prop/bar",1);
        set("weapon_prop/wit",1);
        set("weapon_prop/sou",2);
        set("weapon_prop/con",2);
      init_fist(35);
        setup();
set("wield_msg", HIR"$N�w�w���W�@��$n"HIR"�A���M�@�}����q$N"HIR"��ߩb�˥X�ӡA�O�H�h�o�C\n"NOR);
}


//�ڤ����D�S����g...so...�A��s... :P

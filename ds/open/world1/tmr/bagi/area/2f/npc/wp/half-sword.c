#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�b�I���C",({"half long sword","sword"}));
        set("long",@long
    �o�O�@��w�g�_�F�b�I�����C�A���O�C�����o�۳��˪�����A���G��
���@�r�C�C�`�W��۪��r�˦��w�ҽk���M�A�ݼˤl���Cű�������v�w�[�C
long
        );
          set_weight(5000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",4000);
                set("volume",3);
                set("material","iron");
        }
        init_sword(35);
        set("waepon_prop/str",1);
        set("waepon_prop/dex",1);
        set("limit_str",20);
        set("limit_dex",20);
        setup();
}

void attack(object me,object victim)
{
        int damage,def;

        ::attack();
        if(!me ||!victim ) return;
        if( random(100)<30 && victim->query_skill("dodge") < random(200) ) {
                message_vision(HIG"$n�@�Ӥ��p�߳Q$N��W���b�I���C�������L�@�Ӥp�f...\n"NOR,me,victim);
                victim->apply_condition("poison", 5);
        }
        return ;
}




#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
set_name(MAG "�ӤA"HIY"��"HIB"�C"NOR, ({"tai-yue sword", "sword" }) );
        set("long",
        "�o�O�@��ѯ���d�U�Ӫ����C�A���ۤ��i�i�H�����K�A���P��
�ݬ��N�O�a�o��C�b�Z�L���X�W�����C���C�C�`���ۤ@�q�����A
��O�K�[�F�C�������C\n"
        );
          set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",200000);
                set("material","iron");
        }
                set("waepon_prop/int",2);
        set("limit_str",10);
setup();
              init_sword(100);
}


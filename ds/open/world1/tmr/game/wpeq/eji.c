//�x�W�C���Ĥ@������ �Ĥ@�W eji ���~ -by tmr- 2000/5/20

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name("����", ({ "eji sword","sword" }) );
        set("long",@long
�x�W�C���Ĥ@������ �Ĥ@�W eji ���~
    �o�O�@�⬰eji�M�����C�A�C�ݰ_�ӥ����L�_�A
���O�p�G�A�J���[��A�|�o�{���M�|���@�ٲH�H��
�ť��b�C���W�y��A�b�C�`�W��۶�����r�C
long
);
            set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1500);
                set("material", "iron");
                set("volume",3);
        }
        set("weapon_prop/hit",5);
      set("wield_msg","�����ť��y��]���$N�M�C�A�@�}�l���_���H�C\n");
          set("unwield_msg","$N�⤤�żv�@�{�A�C�w�^��C�T�C\n");
        init_sword(20);
        setup();
}

int query_autoload() { return 1; }

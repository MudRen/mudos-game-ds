//�t�Ϭ��ʲĤT�W �\����(valen) §�� -by tmr-
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIC"�p���C"NOR, ({ "valen sword","sword" }) );
        set("long",
"�t�Ϭ��ʲĤT�W �\\����ұo����§���C\n"
"�o�O�@��ѼC�L�ܺɲ��ͤߦ�ű�y���C�A�צ~�b�s�������l���Ѧa��\n"
"�ءA���G�w���F�ʡA�C�����o�X�}�}����A�ϩ��P�j�۵M�ۤ��I���A�b�C���C\n"
"�`�W�観��~�C�L�Ҽ��g���@�����l�A���W���u�p�G�����D�v...."
);
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1500);
                set("material", "iron");
                set("volume",3);
        }
        set("weapon_prop/int",1);
        set("weapon_prop/hit",5);
set("unwield_msg",HIC"$N��U�p���C,���W�����𺥺��a����,$N�����v�����ܱo�M��\n"NOR);
            set("wield_msg",HIC"$N���_�p���C,�C���W������v����¶��$N,��$N�����v�ܱo���Ұg��\n"NOR);
        init_sword(35);
      setup();
}

int query_autoload() { return 1; }


#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIY"��"YEL"�I"BLINK"�r"NOR,({"kill sword","sword";

        set_weight(5000+random(2000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"�o��C�O��Ф��t���A�i�H�P���쥦�����A���o�]�a����"
                      "�j������A�����D���쩳�O���O���C\n"NOR);
                set("volume",2);
                set("unit", "��");
                set("value",12500);
        set("limit_skill",60);
        set("material","silver");
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",35);
        }
        init_sword(70);
        set("wield_msg","$N�q�S�f���ƥX�@��$n�A�n�ɦ��$N�����W���o;
        set("unwield_msg", "$N�N�⤤��$n���^�S���C\n");
        set("replica_ob", __DIR__"dsword.c");
        setup();
}
void attack(object me,object victim)
{
        int damage,str,dex,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("str")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIY"$n�ɥX�@�D���A�|�P�}�l���t�F�_��\n"NOR
        +HIG"�@�D�ѹp�����C���� �� �� \n"NOR
        +HIR"���a���A�b$N���e�@���m���{�L...�q�C���o�X���D�C�~��$N�ӥh�g�h�C\n"NR
        +HIB"���G�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR
        ,victim);
        return;
        }
}

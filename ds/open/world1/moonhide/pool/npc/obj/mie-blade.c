
#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
void create()
{
        set_name(HIM"���y�]���M"NOR,({"evil-god blade","blade","evil"}));

        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "�W�j���L�ۻs�y�A�[�W�c�]��G���y�X���]�ʤ��@�C\n"NOR);
                set("volume",2);
                set("unit", "��");
                set("value",20000);
                set("limit_skill",50);
                set("material","silver");
        }

        init_blade(65, TWO_HANDED);
        set("wield_msg","$N�˳�$n��A�b�˪��]�ʫK���[�b$N���W�I\n"NOR);
        set("unwield_msg","$N���_$n��A�@���^�k���`�C\n"NOR);
        set("replica_ob", __DIR__"evil-blade.c");
        setup();
}

/*
void attack(object me,object victim)
{
        int damage,str,con,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("str")-random(22);
        con = me->query("con")-random(20);
        random1 = 1+random(2);
        damage = random1*(str+con);
        victim->receive_damage("hp", damage, me );
        message_vision(
HIR"\n\t�⤤���M�]�ʤj�o�A�ƹD�`���ܱq�M��«�X�A\n"
HIW"\t�j���B�e���B�ᰭ�B�l���ܤƨ��ƹD�u��A\n"
HIG"\t����$N����¬�ޡB�����ޡA�ϱo$N���W�]��L�k���X�I�I\n"

HIM"\t(�y��"+damage+"�I���ˮ`�I�I)\n\n"NOR      
                ,victim);
        return;
        }
}
*/

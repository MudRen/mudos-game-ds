#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
 set_name(HIC"�B�E���ɾԩ�"NOR,({"ice storm axe","axe"}));
set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long","    �o����Y�ݨӥ����L�_�A�N���@���K��@�ˡA���O
    �~�����F�@�h�������B�A�õo�X���M�B����C�j���O�����b
    ���s�W�����Y�A����g�~�֤믫�����O�@�A�~�o�w�֦��p���j��
     �O�q�a�C\n");
set("value",4500);
                set("material", "steel");
}
init_axe(855);
set("wield_msg","$N�N$n���b�⤤�A$N�n�ɥR���O�q�A��$N���Ǫ��H�o�N������Ÿ");
set("unwield_msg", "$N�N$n���^�y��A�N��ש󰱤�F�C\n");  
        setup();
}
void attack(object me,object victim)
{
int damage,str,dex;
if( random(100)>70)
    {
        /*   COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),2);*/
str = me->query("str");
dex=me->query("dex");
damage=(str+dex)*(1+random(10));
        victim->receive_damage("hp", damage, me );
message_vision("                  �B�E���ɾԩ��M�o�X�j�j�����~

                       �q�ѤW�l��Ӥ@�}�B�r

              �V$N���h�I�I�I�y��$N"+damage+"�I���ˮ`�I�I�I�I\n",victim);
         return;
        }
    return;
}

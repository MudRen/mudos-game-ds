#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
inherit F_UNIQUE;
void create()
{
set_name("�d���P",({"cloud dagger","dagger"}));

set_weight(700);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("long","�@��զ⪺�P���A���o�X�_�������~�A�W�����H��
�N���񪺤��𵲦����B�A���p��K���H������b�b�W�C\n");
set("unit", "��");
set("value", 17000);
set("material","steel");

set("limit_con",10);
set("limit_dex",10);

set("wield_msg", "$N�����@���A�@�D�H��ѳS���e�g�ӥX�A���J$N����W�C\n");
set("unwield_msg","$n�����ƤJ$N���S��......���ѴH�N�]�H�����u�F�C\n");

set("weapon_prop/dex",7);
set("weapon_prop/hit",7);

set("weapon_prop/damage", 17);
set("combat_msg", ({
     HIC"$N���O�@�R�A$w�W���H��p������N$n�ιγ��I"NOR,
     HIY"$w�b$N��W���p�����@��A�H���p���α��ժ��t�ק�V$n��$l"NOR,
    HIG"$N�⤤��$w��M�����I�H��$N���ʧ@�X�{�b$n��$l����A���۴N�O�����@��I"NOR,
     }) );

set("replica_ob",__DIR__"stonedragon_d");
init_dagger(27);

setup();
}
}                      

void attack(object me,object victim)
{
int damage,con,dex,dodge;
dodge=me->query_skill("dodge");
if( random(100)>(100-dodge/5))
    {

dex=me->query_dex();
if( (dex)>(120))
{
   dex=(120);
}
con=victim->query_con();
damage= ((dex)/(7+random(3)))*((dex)/(3+(random(con/10))));
        victim->receive_damage("hp", damage, me );
message_vision(HIG"
              �d���P�W���H���M�I�J$P�|�Ϧ��e�����I
              $P����H���O�G�X�A���H��L��j�l�r�P�A
              $P�餤���峺�H�۴H��Ѥ�դ��E�g�ӥX�I
              �y��$P"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim);
                             
if(damage>199)
{
   message_vision(HIR"$N�u�P�줦�Ф@�Ѽ@�h�A���O����ť�ϳꪺ�b�餺��«�I�I\n"NOR,victim);
   victim->receive_wound("body",(7+random(7-(dex)/20)));
}
         return;    

        }
    return;
}              



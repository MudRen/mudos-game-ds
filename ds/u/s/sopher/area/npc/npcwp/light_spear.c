#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
     set_name(HIW"�����j"NOR, ({ "light spear","spear" }) );
     set_weight(2000);
     if( clonep() )
     set_default_object(__FILE__); 
     else {
           set("unit", "��");
           set("long", "\n");
           set("value", 10000);
           set("material", "steel");
}
           init_fork(200);
           set("wield_msg", HIW"$N�N$n���b�⤤�A$N�j�ܤ@�n�G ���ڡI �j����M��X�@�Dģ�����~�I\n"NOR);
           set("unwield_msg", HIW"$N�N$n��U�A���D��¶�b�����j�����~���������L�ܡI\n"NOR);
          
           setup();
}
void attack(object me,object ob)
{
int damage,str,con,dodge;

if( random(100)>70)
{

str = me->query_str();
con = me->query_con();
dodge = -COMBAT_D->attack_factor(me,"skill_type") - COMBAT_D->dodge_factor(ob,"dodge");
damage=(con+str-random(ob->query_armor()))*(3+random(5));
if( damage < 40) damage = 40 +random(10);
message_vision(HIW"\n     $N�N�����j���ߦb�ĤH���e\n\n"+
HIY"   �A�����N�]�k�O���E�b�j�f\n\n"+
HIR"   ��M�I   �j�b��X�@�D����ģ�����~�I\n\n"+
BLU"   $N½�ਭ�ΡA�H��s�j�A�ѪŹy���ܪ����P�f�H!\n\n"+
HIG"   �K�K�K�K�K�K�K�K�K�K�K�K�K�K      �t\n\n"+
   "   �K�K�K�K�K�K�K�K�K�K�K�K�K�K\n\n"+
HIW"   �K�K�K�K�K�K�K�K�K�K�K�K�K�K      ��\n\n"+
HIM"   $N��M�j�ܤ@�n�G\n\n"+
HIW"            ���ڡI\n\n"+
HIY"   �@�D���~�q�j�b�g�X�I\n\n"+
   "        ���D�t���H�p�^�U�v���ծg�V�ĤH!!!"NOR,me);
 
if( random(100) < dodge)
    {
      message_vision(HIG"�u��$N���Τ@�{�A���u�q$N���������ӹL\n\n"NOR,ob);
    }
  else
    {
            ob->receive_damage("hp", damage, ob );
      message_vision(HIC"�����کR���F$N\n\n"+
                     "�b�@�����j�z������$N�y���F"+damage+"�I���ˮ`\n\n",ob);
    }
         return;

    }
  return;
}

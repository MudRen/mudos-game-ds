#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
 set_name(HIB"����"NOR,({"huge axe","axe"}));
 set_weight(44550); //damage*50�N�O�ӪZ�������q
 set("value",5000);   //damage*5�N�O�ӪZ��������
 set("amount",1);  //���~�b�ө���ɦ��X�ӥi�H��!
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit","��");
  set("long",YEL
      "    �o����Y�j�ӨI���A�@��H���|���_�ӡA�ݵۥ��A�A���T�Q�h��\n"
      "�o�򭫪����Y�A�a�ۥ������H�g�����D�F�A�u���i�H���ӱ��ĦӤ��|\n"
      "�v�T�ۤv���ԤO��?\n"
      NOR);     // �A�C�I�B�G
  set("material","steel"); //blacksteel�]�i�H....
  set("axe",50);   //�]�wskills��
 }
 init_axe(891); //or init_sword(15)���ҳy����damage�q

 set("wield_msg",HIG"$N�C�C���N���Y���F�_�ӡC\n"NOR);
 set("unwield_msg",HIG"$N�P�F�@�f��A����Y��U�A�ϤF�ϻĵh�����u�C\n"NOR);

 setup();
}

int fail_eq(object me)
{
 if(me->query("str") <45)
 {
  message_vision(HIY"$N�ܧV�O���Q���_�o����Y�A���٬O�����_�ӡC\n"NOR,me);
  return 1;
 }
 return 0;
}

void attack(object me,object victim)
{
 int damage;
 if(random(100)<60)
 {
  damage=891+random(2000);
  victim->receive_damage("hp",damage,me);
  message_vision(HIY"$N���|����A�µ�$n�ĤO���Y�A�U�C\n"NOR,me,victim);
  message_vision(HIR"�i����$N�˥i�����A"+HIW+"����F:"+damage+"�I�ˮ`�C\n",victim);
         return;
 }
 return;
}


#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
 set_name(MAG"�d���M"NOR,({"sorrow blade","blade","sorrow"}));
 set_weight(10000);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "��");
  set("long",HIG"�o��M�A��֦��̬O�֤w���i�ҡA����M�w�g�۷�j�ѡC
�A�٥i�H�Pı����A�o��M���D�H�A���g���L����Ʊ��C
���H�����A�ܥ椧�q�A���H�����E�D�D�D�C\n"NOR);
  set("value",20000);
  set("material", "steel");
  set("wield_msg","WHT$N�C�C���C�U�Y�A�ޥX$n�A�@�}�}�d�ˤ���q$N�����W���o�X�ӡC\n"NOR);
  set(CYN"unwield_msg", "$N�N�⤤��$n���^�M�T�C\n"NOR);
 }
init_blade(51);
 setup();
}
void attack(object me,object victim)
{
 int damage,hp,maxhp,mp;
 me=this_player();
  hp=me->query("hp");
  maxhp=me->query("max_hp");
  mp=me->query("mp");
 if ( hp < maxhp/10 )
 { 
   damage=2000+random(5) * (hp+mp);
  message_vision(HIY" �d���M�l���F�Ҧ��ϥΪ̪��O�q�A���X�d�h�@���I�I�I
    �y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim); 
  victim->receive_damage("hp", damage, me );
 me->set("hp",1);
 me->set("mp",0);
 return;    
 }
}

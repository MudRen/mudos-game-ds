#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB"�M�ݪ��H"NOR, ({ "gold's man", "man" }) );
        set("race", "robot");
        set("age", 1);
        set("long", @long
�A�����ݨ체�e�����Τ����@�ӤH,�A�w���@��,�o�{�L��ӬO�Q�@�D�D�����������ҥ]���
�L�򳬵�����,�f���]���a���۩G��,�Ӥ@�D�D�����Z�u���]�q���W�_�X�ӤF
�A�ݵ۬ݵ�..���M�o�{���Τ��٦��ۼƤQ�����s�H�ۯu���ӫ_�X�F�Y��
�N���n��A���e���H�]������.
long);
        set("level",1);
        set("mobhp",300000000000);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        setup();
}
int receive_damage(string type,int damage,object who)
 {
  if( !who ) return 0;
  who->add("exp", 1000); 

  //who->add("popularity",1);  
  who->add("combat_exp",10); 
  who->add("evil",1);
  who->add("bank/past",1000);   
  //who->add("mud_age",1);
  who->add("MKS",1); 
}



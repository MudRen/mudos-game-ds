#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIG"�۬h"NOR, ({"xiangliu"}) );
  set("long",@LONG
�۬h��A�H���D���A�����C��A�ʱ��ݻųg���C�L�����鹳������Ĳ
��@�˧ᦱ�b�@�_�A�㦳�p���s�@��۫B����O�A�X�G�O�u�n�L��Ĳ
�쪺�a��A���W�N�|�Ƭ����A�A�s�L�Į�άO�R�X�Ӫ��æR���A���|
�N�ΨU���g�a�Ƭ��L�k�ѺءA�ܦ����`�𪺪h�A�A�樫���t�׷�����
�t�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",300);
  set("level",45+random(5));
  set("title",GRN"  ���~ "NOR);
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "����","�ݳ�","����" }) );
  set("verbs", ({ "bite","crash" }) );
  set("chat_chance", 30);
  set("chat_msg", ({
   HIG"�۬h"NOR"���D���b�a�W����A�Φ��@���_�۴c�𪺤��y�C\n",
   HIG"�۬h"NOR"�E���Y�A�Q�K���Ѻ񪺲����@�_�n�ۧA�A�ϧA�����o��C\n",
   HIG"�۬h"NOR"��ʵ��񪺳D���A�������a�ݵۧA�C\n",
     (: random_move :),
     }));
  setup();
}

void init()
{        
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
/*
  switch( random(19) )
  {
    case 0:
         say(HIG"�۬h"NOR"��M�@�ȷϮ����b���O���C\n");
         destruct(this_object());
         break;
  }
*/
} 

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->add("popularity",1); 
  tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);     
  switch( random(100) )
  {
    case 0..29: new(__DIR__"eq/xiangliu_pill")->move(this_object());
         break;
    case 90..99: new(__DIR__"eq/xiangliu_cloth")->move(this_object());
         break;
  }
  ::die();
  return;
}

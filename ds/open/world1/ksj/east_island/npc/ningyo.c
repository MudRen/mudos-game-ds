#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�H��", ({"ningyo"}) );
  set("long",@LONG
�����W�b���M�H���@�Ҥ@�ˡA�ӤU�b���o�O�����A�仪�����C�ݨ�H
���O���N���x���A���ڻ��u�n�Y��H�����׫K����ͤ�����I
LONG
);
  set("race", "human");
  set("unit","��");
  set("age",200);
  set("gender", "�k��" );
  set("level",25);
  set_skill("unarmed",40);
  set_skill("dodge",40);
  set_skill("parry",30);
  add("addition_armor",20);
  setup();
  carry_object(__DIR__"eq/ningyo-meat");
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
 
        switch( random(100) ) {
        case  0..2: new(__DIR__"eq/ningyo-necklace")->move(this_object());
        break;}
        ::die();
        return;
 }

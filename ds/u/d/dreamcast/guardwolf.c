#include <ansi.h>
inherit NPC;

void create()
{
         set_name("�үT�u�@��",({"guard wolf","wolf"}) );
          set("title","�ʦ~���~");
  set("long",@LONG
�e�N�O���C���ΨӦu��ѧ��ʦL�����~
LONG
);
   set("attitude", "aggressive");

set("combat_exp",50000);
set("max_hp",15000);
set("max_ap",1000);










                 

  set("race", "beast");
  set("unit","��");
  set("age",100);
  set("level",45);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l","����" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",1100);
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
        message("world:world1:vision",
  HIG"\n�i�ѧ��b�@�j" +HIW"�ѧ��j���G�u�z�������A"+ob->name(1)+"�F���n���A��ڪ��ʦL�Ѷ}�F�C\n\n"+NOR
        ,users());
        ob->add("popularity",3); //�n��
        ::die();
        //destruct(this_object());
        return;
}


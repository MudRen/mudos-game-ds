#include <ansi.h>
inherit NPC;


void do_mucus()
{
        if( is_busy() ) return ;
        if( !objectp(query_enemy())) return ;
        message_vision(GRN "$N���$n�R�X�F�f�H�Y���ĲG...\n" NOR, this_object(), query_enemy() );;
        query_enemy()->add_busy(1);

}

void create()
{
  set_name( "�H�G��" , ({"mucus odd","odd"}) );
  set("long",@LONG
�o�O�@���H�G�Φ����Ǫ��A�o���H�G�㦳�j�P���G�k�ʡA
�q�`�Q�]���ͪ����O�����@���C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age", 3);
  set("gender", "����" );
  set("level", 15 );
  set("limbs", ({ "�H�G" }) );
  set("verbs", ({ "bite", "claw" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
      set("chat_chance_combat",20);
        set("chat_msg_combat",({
                (: do_mucus :),
        }) );
  setup();
}


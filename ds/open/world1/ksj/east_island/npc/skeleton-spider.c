#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�u�\\�j��",({"skeleton spider","spider"}) );
        set("long",@LONG
�@�����j���¦�j��A��Φ���O������j�A�i�Ȫ��O�e���������M
�O�ѱa���Ǿl��ת��u�\�Y�Ҳզ��C�ѩ���F�L�k�W��ɤѦӪ����b
�j��W�A�~�Φ��o�ةǪ��C
LONG
);
        set("race", "���~");    
        set("unit","��");
        set("age",94);
        set("attitude", "aggressive");
        set("level",27+random(4));
        set("limbs", ({ "�Y�ݳ�","�Ʋ�","����","����"}) ); 
        set("verbs", ({ "bite","claw" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�u�\\�j�︡�����u�\\�Y�����w�U�ͤ��A�ϱo�Ů𤤥R���G��C\n",
        }));                                
        setup();
        add_money("coin",500);
}

int special_attack(object me, object target, int hitchance)
 {
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7) )
  {
    message_vision("\n$N�i�L�R�X�@�λj�ﵷ�A���F$n����}�A$n�@�ɶ��L�k�ʼu�C\n\n", me, target);
    target->add_busy(3);
    return 1;
  }
  return 0;
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
        case  0..4: new(__DIR__"eq/bogle-bead")->move(this_object());
        break;
        case  5..9: new(__DIR__"eq/hands-design-page")->move(this_object());
        break;}
        ::die();
        return;
 }

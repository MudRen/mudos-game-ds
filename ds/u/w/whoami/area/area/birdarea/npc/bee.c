#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�ܺت��Y��",({"tigerhead bee","bee"}));
        set("level",30+random(10));
        set("race", "���~");
        set("age", 23);
        set("long", "���r���@�ظ����A���M�O�����A���O�L�o�Τ��l�ӧ����H�C\n");
        set("limbs", ({ "�Y��", "����", "�ͻH", "���l"}) );
        set("verbs", ({ "claw","crash"}) );
        setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision(MAG"\n$N�Φۤv���r�w�A�r�O��V$n�I\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100),me);
    target->apply_condition("poison", target->query_condition("poison")+(random(5)+5));
    return 1;
  }
  return 0;
}

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        switch( random(1000) ) {
        case 0: 
        newob=new(__DIR__"obj/scroll");
        newob->move(this_object());
        break;
        case 1..200:
        ob->add("popularity",1);
        tell_object(ob,HIG"�A�o��F 1 �I�n��\n"NOR);
        break;
        default:
        break;
        }
        ::die();
        return;
}


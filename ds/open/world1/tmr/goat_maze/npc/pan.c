
#include <ansi.h>

inherit NPC;

void do_super(object me);
varargs int receive_damage(string type, int damage, object who);

void create()
{
        set_name(HIG "�����ﮦ" NOR,({"bariour pan","bariour","pan"}));
        set("gender", "�k��");
        set("long",@LONG
�@�}ģ���������h�A�������A�A�L�k�ݲM�������ﮦ�����ۡA�u��
�D���󪺦��̨��C
LONG
        );
        set("level", 60);
        set("age", 800);
                set("race","celestial");
        set("title","�Ϩk���g�c");
        set_temp("fly",1);
        set_temp("apply/damage",200);
        set_temp("apply/armor", 400);
        set_temp("apply/shield",300);
                set("addition_hp", 30000);
                set("evil",-100);
                set("max_hp",50000);
        setup();
                set_temp("apply/wit", 3);
                set_temp("apply/bar", 3);
                set_temp("apply/bio", 3);
        set_living_name("bariour_pan");

                switch(random(4)) {
                        case 0:
                                carry_object(__DIR__"obj/pan_ankle1")->wear(); break;
                        case 1:
                                carry_object(__DIR__"obj/pan_ankle2")->wear(); break;
                        case 2:
                                carry_object(__DIR__"obj/pan_ankle3")->wear(); break;
                        case 3:
                                carry_object(__DIR__"obj/pan_ankle4")->wear(); break;
                }

        carry_object(__DIR__"obj/pan_necklace")->wear();
}

int special_attack(object me, object target, int hitchance)
{
        if(!me) return 0;
        if( query_temp("special_attack") ) return 0;
        if( random(100) < 30) return 0;

        if( target->is_busy() || random(100) < 20)
        {
            set_temp("special_attack", 1);
        set_name(HIY "�����ﮦ" NOR,({"bariour pan","bariour","pan"}));
                me->attack();
                me->attack();
        set_name(HIG "�����ﮦ" NOR,({"bariour pan","bariour","pan"}));
                delete_temp("special_attack");
                return 1;
        }

        if( random(100) < 80)
        {
                // �s�����
                set_temp("special_attack", 1);
                message_vision("$N"HIW"���Ϸ�E�g�X���䪺�զ���~�A�಴���G����y�s���I�I\n"NOR, me);
                call_out("do_super", 1 + random(2) ,me);
                return 1;
        } else {
                // �ɦ�

        }

        return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = me->query_enemy();
  delete_temp("special_attack");
  if(!inv) return;
  if(!me) return;

  message_vision( HIY"\n�b�Ť��Φ��L�ƪ��u���@��"HIW"�զ�Ϸ"HIY"�A�gŧ�ӨӡI�I\n"NOR, me);
  for(i=0;i<sizeof(inv);i++)
  {
          if( !environment(me) ) continue;
          if( !inv[i] || !environment(inv[i]) ) continue;
          if(environment(me) != environment(inv[i]) ) continue;

          damage = query_damage() + random(query_damage());
          if( inv[i]->is_busy())
                damage -= random(inv[i]->query_shield());
          else
                damage -= random(inv[i]->query_shield()/2);

      damage += query_temp("horn") * 50;
      damage = COMBAT_D->Merits_damage(me, inv[i], damage, "wit" );
      if(damage < 100 ) damage = 100 + random(100);
      message_vision(HIR"$N"HIR"�L�Ұ{�סA"HIW"�զ�Ϸ"HIR"������V�ݽ��ӹL�A�a�X�g�m�ӥX����y�I�I"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
      // �̦h�u�|��15��
      if( query_temp("horn") < 15  && userp(inv[i]) ) {
              add_temp("horn",1);
              new(__DIR__"obj/pan_horn.c")->move(environment(me)); // ���@�ڨ�
      }
  }
  me->start_busy(2);
  return;
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
        object sw;

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");

        if( objectp(who) && type=="hp")
                set_temp("last_damage_from", who);
        sw=who->query_temp("weapon");

               if(random(100)<50)
               {
                        damage=1;
             if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 70 ) 
                    {
                 sw->unequip();
                                                message_vision(HIY "\n�@�Ѩ�󪺦��̨������q��B�ǨӡA$N"HIY"�r�@�D��n���Y������A���u�ĳn�L�O�C\n" NOR,who,sw);
                                                message_vision(CYN "($N�渨�F��W���Z���F�C)\n" NOR,who,sw);
                     } if(random(100) < 40 ) {
                                                message_vision(HIY "\n�@�Ѩ�󪺦��̨��Q���b��y�s���A$N"HIY"�uı�o�ݤf�дe�����A�����Ϥ��X�O��C\n" NOR,who);
                                                who->start_busy(2);
                                        } else {
                                                message_vision(HIM "\n$n"HIM"�����F�ѥb�ѡA�~�r�M�oı�ۤw�������O���Ů�o�ۡC\n" NOR,this_object(),who);
                                        }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
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

          // �������B
         "/open/world1/tmr/goat_maze/stairway4.c"->open_rain();

                message("world:world1:vision",
HIG"\n\t" + ob->name(1) + HIG"�ש����ѤF�����ﮦ�A�����S�Q��v���m���B�o�V�B�O�L�B��A�����I�I\n\n"+NOR
        ,users());

        ob->add("popularity", 7);
        tell_object(ob,HIG "(�A��o 7 �I�n��C)\n" NOR);

        ::die();
        return;
}



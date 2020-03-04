inherit NPC;
#include <ansi.h>

void do_super(object me);

void create()
{
    set_name(HIW"�կT��" NOR, ({ "white-wolf god", "wolf", "god"}) );
	set("race", "evil");
	set("age", 140);
	set("level", 40);
    set("unique", 2);
    set("long", "�կT���O�w�g���몺�T���A�u�@�۰w��L�A�����O���ժ��T��A�����D�ݮ`�L�h�֥��F�C\n");
    set("attitude", "aggressive");	
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "�e��" }) );
	set("verbs", ({ "bite", "claw" }) );
	set_temp("apply/armor", 100);
	set_temp("apply/shield", 100);
	set_temp("apply/damage", 150);
	set("max_hp",25000);
    set("evil",-100);
	setup();
	
	carry_object(__DIR__"obj/illimitable-armor.c")->wear();
	carry_object(__DIR__"obj/illimitable-helmet.c")->wear();
}


void die()
{
        object ob;
        string name;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        
        name = sprintf(HIR"%s(%s)" NOR, ob->name(1), ob->query("id"));
        message("world:world1:vision",
        	HIY"\n��~���a���ħJ���ǨӤ@�h��H�������G\n\n"+NOR
        	HIW"\t���ħJ�i�h" + name + HIW"�ݱ��F�w��L�ǯT�����u�կT���v"+HIW"�F�I�I\n\n"+NOR
			, users());
        ob->add("popularity", 3); //�n��
        tell_object(ob,HIG"(�A�o��F 3 �I�n��C)"NOR);
        
        ::die();
}

int special_attack(object me, object target, int hitchance)
{
        if(!me) return 0;
        if( query_temp("special_attack") ) return 0;
        if( random(100) < 30) return 0;

        if( target->is_busy() || random(100) < 20)
        {
            set_temp("special_attack", 1);
            me->attack();
            me->attack();
            delete_temp("special_attack");
            return 1;
        }

        if( random(100) < 80)
        {
                // �s�����
                set_temp("special_attack", 1);
                message_vision(HIW"$N"HIW"�i�}��֤j�f�R�X�����S���B���u�D�a�ȦB�v�I�I\n"NOR, me);
                call_out("do_super", 2 + random(2) ,me);
                return 1;
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

  message_vision( HIW"\n�಴���A�u�D�a�ȦB�v�w�g�����b�o���j�a�W�A�Ҧ��ͪ�������i�ΡI�I\n"NOR, me);
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

      damage = COMBAT_D->Merits_damage(me, inv[i], damage, "tec" );
      if(damage < 100 ) damage = 100 + random(100);
      message_vision(HIR"�ܴH�ܳ����ȦB�I�J$N"HIR"����Ŧ���ơA�y�����H��_�����ˡI�I"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
  }
  me->start_busy(2);
  return;
}

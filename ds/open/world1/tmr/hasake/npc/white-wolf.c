inherit NPC;
#include <ansi.h>

void do_super(object me);

void create()
{
    set_name(HIW"白狼神" NOR, ({ "white-wolf god", "wolf", "god"}) );
	set("race", "evil");
	set("age", 140);
	set("level", 40);
    set("unique", 2);
    set("long", "白狼神是已經成精的狼妖，守護著針樹林，全身是雪白的狼毛，不知道殘害過多少生靈。\n");
    set("attitude", "aggressive");	
	set("limbs", ({ "頭部", "牙齒", "前腳", "後腳", "前爪" }) );
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
        	HIY"\n塞外之地哈薩克草原傳來一則驚人的消息：\n\n"+NOR
        	HIW"\t哈薩克勇士" + name + HIW"誅殺了針樹林灰狼之神「白狼神」"+HIW"了！！\n\n"+NOR
			, users());
        ob->add("popularity", 3); //聲望
        tell_object(ob,HIG"(你得到了 3 點聲望。)"NOR);
        
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
                // 群體攻擊
                set_temp("special_attack", 1);
                message_vision(HIW"$N"HIW"張開血盆大口吐出像霧又像雨的「乃窮玄冰」！！\n"NOR, me);
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

  message_vision( HIW"\n轉眼間，「乃窮玄冰」已經漫延在這片大地上，所有生物都受到波及！！\n"NOR, me);
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
      message_vision(HIR"至寒至陰的玄冰侵入$N"HIR"的五臟六腑，造成難以恢復的內傷！！"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
  }
  me->start_busy(2);
  return;
}

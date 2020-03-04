inherit NPC;
void create()
{
        set_name(MAG"毒"NOR"狐狸",({"poison fox", "fox"})); 
        set("title",HIW+BLK"魔獸");     
        set("level",30+random(30));
        set("attitude", "aggressive");
        set("race", "野獸");
        set("max_hp",5000+random(1000));
        set("Merits/bar",2+random(2)); 
        set("age", 16);
        set("evil",250+random(250));
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(15))
  {
    message_vision("\n$N對$n吐出一口毒霧，$n已身處毒霧中了！\n\n"NOR, this_object(), target);
    target->apply_condition("poison", me->query_condition("poison")+random(3));
    target->receive_damage("hp",random(20),me);
    return 1;
  }
  return 0;
}

void die()
{
        object me=this_object();
        object ob,obj;
        LOGIN_D->set_reboot(0);
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        switch(random(8)){
        case 0:
        ob->add("popularity",1);
        tell_object(ob,HIG"你得到 1 點聲望。"NOR);      
        break;
        default:
        break;
        }     

        message_vision("\n$n"HIC"順手將"NOR"$N"HIC"的頭砍下，放進袋子裡。\n"NOR,me,ob);
        ob->add("quest/ko_fox",random(3)); 
        ::die();
        return;
}        


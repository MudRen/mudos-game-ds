inherit NPC;
#include <ansi2.h>

void combat_ai();

void attacked(object me, object target, int damage1, int damage2, int damage3)
{
     target->receive_damage("hp",damage1);
     target->receive_damage("mp",damage2);
     target->receive_damage("ap",damage3);
     COMBAT_D->report_status(target);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
     return;
}

void haltbusy()
{
       if( !random(3) ) return;
       message_vision(HIY"\n$N�B�W�������o�X�}�}���~�X���}�ӡA$N�����߱q���w��_�F�L�ӡC\n"NOR,this_object());
       this_object()->add_busy(-10);
       combat_ai();
       return;
}

void combat_ai()
{
     object *target, me, weapon;
     int damage, i;
     target = all_inventory(environment(this_object()));
     me = this_object();
     weapon = me->query_temp("weapon");
     if(!target) return;

     if( me->is_busy() ) haltbusy();

     i=sizeof(target);
     while( i-- ) {
            if( this_object()->is_killing(target[i]) || this_object()->is_fighting(target[i]) ){
                switch( random(3))
                {
                        case 0:
                             damage = target[i]->query("max_hp")/8;
                             message_vision(HIR"\n$N"HIR"����@���A�@�ίP������$n�ӥh�A",me,target[i]);
                             if(random(3)) {
                                           message_vision(HIR"$N�Q$n"HIR"���P���N�ӵJ�Y�J�y�I"HIR"("+damage+")\n"NOR,target[i],me);
                                           attacked(me, target[i], damage, damage, 0);
                                           } else message_vision(HIR"$N���ө��|�����L�F$n"HIR"�������I\n"NOR,target[i],me);
                        break;
                        
                        case 1:
                             damage = target[i]->query("max_hp")/7;
                             message_vision(HIR"$N"HIR"�j�F�_��áA�y�ɤ@���զϦV$n���Ħӥh�I\n",me,target[i]);
                             if(random(5)) {
                                           message_vision(HIR"$N"HIR"�Q�զϼ��F�ӤH����½�I"HIR"("+damage+")\n"NOR,target[i]);
                                           attacked(me, target[i], damage, 0, damage/2);
                                           } else message_vision(HIR"$N��ۥզϤj�ܤ@�n�G���I�զϨĨıq����ȶ}�F�I\n"NOR,target[i]);
                        break;
                        default:
                                damage = target[i]->query("max_mp")/10;
                                if( !weapon ) return;
                                message_vision(HIR"\n$N"HIR"�⤤��"+weapon->query("name")+HIR"�ܱo�Ӥj�L��A���A$n��y�A",me,target[i]);
                                if(random(8)) {
                                              message_vision(HIR"$N�y�ɦ�y�p�`�A����V���F�����I"HIR"("+damage+")\n"NOR,target[i]);
                                              attacked(me, target[i], 0, damage, damage);
                                              } else message_vision(HIR"$N���ۼA�Ӫ���V�A�a���D�_�A���L�o�P�R�@���I\n"NOR,target[i]);
                        break;
                }
            }
     } 

        if( !me->query_temp("pill") ) return;
        if( me->query("hp") >  me->query("max_hp")/2 ) return;
        if( random(2) ) message_vision("$N�j�ܡG����R�A�礩�ڤO�q�a�I\n", me);
        else message_vision("$N�j�ܡG�p�t�z�I�z�o�a�I\n", me);
        me->receive_heal("hp",query("max_hp")/2);
        me->receive_heal("mp",query("max_mp")/2);
        me->receive_heal("ap",query("max_ap")/2);
        me->clean_condition();
        COMBAT_D->report_status(me);
        me->add_temp("pill",-1);
        return;
}

void create()
{
        set_name(WHT"���紵"NOR, ({"ares"}));
        set("title", HIR"�i�ԯ��j"NOR);
        set("long", "�ǻ������ԯ����p���A�u�@�ۥզϮy\n");
        set("gender","�k��");
        set("level", 55);
        set("age",37);
        set("attitude", "friendly");
        set("int",95);
        set("race","ogre");
        set("chat_chance_combat",200);
        set("chat_msg_combat",({
            (: combat_ai :),
        }));

        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("axe", 100);

        set("max_hp",25000);

         set_temp("pill", 1);
        set_temp("fly",1);
        
        add("addition_damage",170+random(70));
        add("addition_armor", 190+random(80));
        add("addition_shield", 10);
        
        setup();
      
        set_temp("apply/hit",80+random(30));
        set_temp("apply/dodge",40+random(20));

        set_temp("apply/tec", 3);
        set_temp("apply/bar", 7);
        set_temp("apply/bio", -4);
        set_temp("apply/sou", -2);
        set_temp("apply/wit", -2);

        carry_object(__DIR__"wp/barbarian_axe")->wield();
        carry_object(__DIR__"eq/war_plate")->wear();
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
        object sw;

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");

        if( !objectp(who) ) return damage;
        if( environment(this_object()) != environment(who) ) return 0;
        if( objectp(who) && type=="hp")
        set_temp("last_damage_from", who);
        sw=who->query_temp("weapon");

        if(random(100) > 70)
        {
            damage=1;
            if( is_busy() ) haltbusy();
            if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 70 ) 
            {
                sw->unequip();
                message_vision(HIY"\n���p���j�ܤ@�n�A$N"HIY"�y�ɳQ�媺�⤤�@Ÿ�A���p�����խ���$n�C\n" NOR,who,sw);
                message_vision(CYN "($N�渨�F��W���Z���F�C)\n" NOR,who,sw);
            } if(random(100) < 40 ) {
                message_vision(HIY "\n���p�����W���Ҫx�X����_���]���A$N"HIY"���e�@��A�w�Q�������h���C\n" NOR,who);
                who->add_busy(2);
            } else {
                message_vision(HIM "\n$n"HIM"�J�M�o�{�A��~��⪺���M�O�]�k�ۼv�C\n" NOR,this_object(),who);
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
        ob->start_busy(3);
        message("channel:chat",HIY+"�i�����Q�G�c�j"HIC"����R(Athena)�G"+ob->name()+
        "���L�F"+environment(ob)->query("short")+"\n"NOR,users());
        if( !ob->query_temp("kill_12gong") ) ob->set_temp("kill_12gong", 1);
        ::die();
        return;
}


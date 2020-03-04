inherit NPC;
#include <ansi2.h>;

void haltbusy()
{
       if( random(3) ) return;
       message_vision("$N�B�W�������o�X�}�}���~�X���}�ӡC\n",this_object());
       message_vision("$N�����߱q���w��_�F�L�ӡC\n",this_object());
       this_object()->add_busy(-5);
       return;
}

void powerup()
{
        if( !this_object()->query_temp("pill") ) return;
        if( this_object()->query("hp") >  this_object()->query("max_hp")/2 ) return;
        if( random(2) ) message_vision("$N�j�ܡG����R�A�礩�ڤO�q�a�I\n", this_object());
        else message_vision("$N�j�ܡG�p�t�z�I�z�o�a�I\n", this_object());
        this_object()->receive_heal("hp",query("max_hp")/2);
        this_object()->receive_heal("mp",query("max_mp")/2);
        this_object()->receive_heal("ap",query("max_ap")/2);
        this_object()->clean_condition();
        COMBAT_D->report_status(this_object());
        this_object()->add_temp("pill",-1);
        return;
}

void create()
{
        set_name(WHT"����ù���R"NOR, ({"afolodina"}));
        set("title", HIY"�i�����j"NOR);
        set("long", "�ǻ������R�P�����k���Ъ���ù�}���A�u�@�۪����y\n");
        set("gender","�k��");
        set("level", 58+random(7));
        set("age",26);
        set("attitude", "friendly");
        set("race","human");

        set("chat_chance_combat",100);
        set("chat_msg_combat",({
            //(: command("do wield sword,exert xxx"):),
            //(: command("exert xxx"):),
            (: powerup :),
        }));
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("needle", 150);

        set("max_hp", 23000);
        set("max_mp", 6000+random(1200));
        set("max_ap", 4500);
        
        set_temp("pill", 2);
        set_temp("fly",1);
        set_temp("apply/damage",140);
        set_temp("apply/shield",40);
        set_temp("apply/armor", 300);
        set_temp("apply/hit", 80);
        set_temp("apply/dodge", 50);
        set("addition_armor", 40);

        setup();
        set_temp("apply/bar", -2);
        set_temp("apply/wit", 7+random(3));
        set_temp("apply/bio", -3);
        set_temp("apply/sou", -3);
        carry_object(__DIR__"wp/cow_needle")->wield();
        carry_object(__DIR__"eq/afolodina_shoes")->wear();
}


int special_attack(object me, object target, int hitchance)
{
    if(!me) return 0;
    switch(random(7))
    {
        case 0:
        {
        message_vision(YEL"$N������S�A���g�V$n�����ӨӡI\n",me,target);
        if(random(2))
                {
            message_vision(YEL"$N�Q���Ӫ����g�T�S�F�����I"HIR"("+query("max_mp")/10+")\n"NOR,target,me);
            target->receive_damage("mp",query("max_mp")/10);
            COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
            me->start_busy(2);
                }
        else
        message_vision(HIR"$N�]���_�L�ڡA�⭸�Ӫ����g�ɯɧj���b�a�I\n"NOR,target,me);
        }
        break;
        case 1:
        {
        message_vision(HIR"$N��ᦳ���A�@�������V$n�ĨӡI\n",me,target);
        if(random(2))
                {
            message_vision(HIR"$N�Q�������y����F�Ӥj�]�K�I"HIR"("+2*query("max_mp")/15+")\n"NOR,target);
            target->receive_damage("ap",2*query("max_mp")/15);
            COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
            me->start_busy(2);
                }
        else
        message_vision(HIR"$N�t�x�����X�����Ǯ̱������I\n"NOR,target);
        }
        break;
        case 2:
        {
        message_vision(HIR"$N�V$n�g�X�F�R�����b�C\n",me,target);
        if(random(2))
                {
            message_vision(HIR"$N���������סA�ϦӪ�F�W�h�I"HIR"("+2*query("max_mp")/20+")\n"NOR,target);
            target->receive_damage("mp",2*query("max_mp")/20);
            COMBAT_D->report_status(target);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
            me->start_busy(2);
                }
        else
        message_vision(HIR"$N�ݷǤ�V�A���}�F$n���R�����b�I\n"NOR,target,me);
        }
        break;
    }

        return 0;
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
        
        if( this_object()->is_busy() ) haltbusy();
        
        if(random(100)<35)

        {
            damage=1;
           if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 40 ) 
            {
                sw->unequip();
                message_vision(HIY"\n����ù���R�j�ܤ@�n�A$N"HIY"�y�ɳQ�媺�⤤�@Ÿ�A����ù���R���խ���$n�C\n" NOR,who,sw);
                message_vision(CYN "($N�渨�F��W���Z���F�C)\n" NOR,who,sw);
            } if(random(100) < 40 ) {
                message_vision(HIY "\n����ù���R���W���Ҫx�X����_���]���A$N"HIY"���e�@��A�w�Q�������h���C\n" NOR,who);
               who->start_busy(1);
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
        "���L�F"+environment(this_object())->query("short")+"\n"NOR,users());
        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        //ob->set("12gong/libra","done");
        //ob->add("12gong/libra",1);
        //ob->set("title",HIW"�ѩW�y�Ԥh"NOR);
        //ob->save();
        }
        if( !ob->query_temp("kill_12gong") ) ob->set_temp("kill_12gong", 1);
        ::die();
        return;
}

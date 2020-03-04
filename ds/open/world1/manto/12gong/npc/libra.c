inherit NPC;
#include <ansi2.h>;
void powerup();

void create()
{
        set_name(HIG"�ȴ����p��"NOR, ({"astraea"}));
        set("long", "�@��������A�@���ⴤ�ٰ����c���C�����q�k���C\n");
        set("gender","�k��");
        set("title", HIW"�i���q�k���j"NOR);
        set("level", 65);
        set("age",37);
        set("attitude", "friendly");
        set("race","human");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
            //(: command("do wield sword,exert xxx"):),
            //(: command("exert xxx"):),
            (: powerup :),
        }));
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set("max_mp", 7000);
        set("max_ap", 5000);

        set_temp("fly",1);
        set_temp("apply/damage",220);
        set_temp("apply/armor", 260);
        set_temp("apply/hit", 70);
        set_temp("apply/dodge", 50);
        set("addition_armor", 80);

        setup();
        set_temp("apply/tec", 5);
       set_temp("apply/bar", 5);
        set_temp("apply/wit", 8);
        set_temp("apply/bio", 5);
        //carry_object(__DIR__"obj/by_cloth")->wear();
        carry_object(__DIR__"wp/longsword")->wield();
}

void powerup()
{
        message_vision("$N�j�ܡG�p�t�z�I�z�o�a�I\n",this_object());
        this_object()->set("hp",query("max_hp"));
        this_object()->set("mp",query("max_mp"));
        this_object()->set("ap",query("max_ap"));
        this_object()->clean_condition();
        COMBAT_D->report_status(this_object());
        return;
}

int special_attack(object me, object target, int hitchance)
{
    if(!me) return 0;
     switch(random(6))
     {
        case 0:
        {
        message_vision(HIC"$N���ۤ@�n�G�y�A�E�Ѥ���«�X�D�D�����A����$n�I\n",me,target);
        if(random(2))
                {
              message_vision(HIC"$N�Q���j�����b�a�W�A�@�L�b�I�O�q�I"HIR"("+query("max_hp")/20+")\n"NOR,target,me);
              target->receive_damage("hp",query("max_hp")/20);
              target->receive_damage("mp",query("max_mp")/10);
        COMBAT_D->report_status(target);
        me->start_busy(2);
                }
        else
        message_vision(HIG"$N��������A�����D¶�F�h�ְ�~�ܹL�����������I\n"NOR,target);
        }
        break;
        case 1:
        {
         message_vision(YEL"$N���ۤ@�n�G�y�A�@�����s���q���ӥX�A���ڦV$n���h�I\n",me,target);
        if(random(2))
                {
              message_vision(GRN"$N�Q���s�����ڥϤF�ӥ��ۡA$N�y�ɲ��_���P�I"HIR"("+2*query("max_hp")/15+")\n"NOR,target);
          target->receive_damage("mp",2*query("max_mp")/15);
          target->receive_damage("ap",2*query("max_ap")/10);
        COMBAT_D->report_status(target);
        me->start_busy(2);
                }
        else
        message_vision(HIY"$N�κɥ����O��A���@�Ӯ�A���s�����ڥ��q$N���}���O���L�I\n"NOR,target);
        }
        break;
        case 2:
        {
        message_vision(HIR"$N���ۤ@�n�G�y�A�j�a�_�ݡA�L�Ƥg�s��M�V$n�ĹL�ӡI\n",me,target);
                if(random(2)==0)
                {
              message_vision(HIR"$N�p�@�Ӳy�@�ˡA�Q�L�ƥu�g�s�b�Ť����˵ۡI"HIR"("+3*query("max_hp")/20+")\n"NOR,target);
              target->receive_damage("mp",3*query("max_mp")/20);
              target->receive_damage("ap",3*query("max_ap")/20);
              COMBAT_D->report_status(target);
                }
        else
        message_vision(HIR"$N�ݷǤF�g�s�������ŻءA����k��A�~�j�j�����I\n"NOR,target);
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

        if(random(100)<50)
        {
            damage=1;
            if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 30 ) 
            {
                sw->unequip();
                message_vision(HIY"\n�ȴ����p���j�ܤ@�n�A$N"HIY"�y�ɳQ�媺�⤤�@Ÿ�A�ȴ����p�����խ���$n�C\n" NOR,who,sw);
                message_vision(CYN "($N�渨�F��W���Z���F�C)\n" NOR,who,sw);
            } if(random(100) < 50 ) {
                message_vision(HIY "\n�ȴ����p�����W���Ҫx�X����_���]���A$N"HIY"���e�@��A�w�Q�������h���C\n" NOR,who);
                who->start_busy(2);
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

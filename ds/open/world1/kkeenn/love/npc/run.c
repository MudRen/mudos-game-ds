#include <ansi.h>
void whip();
inherit NPC;
varargs int receive_damage(string type, int damage, object who);
void create()
{
        set_name(MAG"�H�T"NOR,({"sen run","run"}));
        set("long" ,
"���������ĤT�N�ǤH�A�m���_������[�����@�k]���@���A��O�����e�p��\n"
"�O��i�q���k�@��C\n");
        set("nickname", HIM"�K�P�l���@"NOR );
        set("attitude", "friendly"); 
        set("age", 25);
        set("gender","�k��");
        set("level", 25);
        set("class1","������");
        set("title",HIC"�������ĤT�N�ǤH"NOR);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
                          (:whip:), 
                          (:whip:), 
        }) );
        set_temp("apply/armor",15);
        set_skill("run_cloud",75);
        map_skill("dodge","run_cloud");
        setup();
        carry_object(__DIR__"obj/whip6")->wield();
         carry_object(__DIR__"obj/pill7");
        add_money("coin",1500);
        }
void whip()
{
        object me=this_object();
        object* target; 
        int dam = random(me->query_skill("whip") + 200);        if(me->is_busy() ) return;
        target=query_enemy();
        message_vision(
"$N�V�A�ĥh�A�I��X�����@�k�Ĥ����y"HIY"�����s���N"NOR"�z\n  �@�l���M�q�������l�u���V�A���\n",me);
        target->receive_damage("hp",dam,me);
        message_vision(HIR"�y���A" +dam+ "�I���ˮ`"NOR"�C\n",me);
    return;
}
void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
}
varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
        if(objectp(who) )
                ::receive_damage(type,damage,who);
        else
                ::receive_damage(type,damage,who);      
 if(query("hp")<query("max_hp")/4 && !is_busy() && !query_temp("eaten") && random(100) > 70 ) 
           {
           command("eat ball");
           this_object()->set_temp("eaten");
           command("grin");                             
           }
        return damage;
}

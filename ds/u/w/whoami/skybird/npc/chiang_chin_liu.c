#include <ansi.h>
inherit NPC;
void normal_ai();
void combat_ai();
void heal();
void create()
{
 set_name("江清流",({"chiang chin liu","chiang","chin","liu"}));
 set("long","他就是尉遲妄的大弟子─江清流•一身武功\皆來自尉遲妄的真傳\n"
            "，內外功\的功\力自然不在話下，再加上他那行俠仗義的作風，也\n"
            "為他贏得了『十萬俠首』的封號•不過你看他眉頭深鎖，顯然是\n"
            "遇到了極大的困難•\n");
 set("attitude","peaceful"); 
 set("age",33);
 set("gender","男性");
 set("level",38);
 set("title",HIR"十萬俠首"NOR); 
 set("str",75+random(10));
 set("dex",75+random(10));
 set("Merits/bar",5+random(3)); 
 set("Merits/wit",3+random(3));
 set("max_hp",6000+random(3000)); 
 set("max_ap",6000+random(3000));
 set("evil",-350);
 set_temp("apply/armor",75+random(18));
 set_temp("apply/damage",75+random(30));
 set_skill("dagger",100);
 set_skill("sky-dagger",100);
 set_skill("unarmed",100);
 set_skill("dodge",100);
 set_skill("parry",100);

 set("chat_chance",5);
 set("chat_msg", ({"江清流嘆了口長氣.... \n",
                   "江清流嘆口氣說:真是一隻神鷹打翻一船人啊....\n",
                   "江清流接著說:可是我們哪裡沒搜過?....\n",
                   "江清流忽然說道:莫非又回到參天古木上神鷹穴了?....\n",
                   (: normal_ai :),  }));
 set("chat_chance_combat",300);
 set("chat_msg_combat", ({
 (: combat_ai :),
 }));
setup(); 
carry_object(__DIR__"eq/cloth")->wear();
carry_object(__DIR__"eq/sob_dagger")->wield();
}

void heal()
{
    object me=this_object();
    message_vision(HIC"$N從懷中掏出一瓶小瓶子，將瓶中液體塗抹在傷口處，傷口便神奇的癒合了•\n"NOR, me);              
    me->receive_heal("hp",random(800));
    me->receive_heal("mp",random(1000));
    me->receive_heal("ap",random(1000));
    return;
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
        message("world:world1:vision",
CYN"\n  武林傳出了一則驚人的消息:\n\n\t『"HIR"十萬俠首"NOR+CYN"』"HIR"江清流"NOR+CYN"居然敗在"+ob->name(1)+"的手上。\n\n"+NOR
        ,users());
        ob->add("popularity",2); 
       tell_object(ob,HIW"(因為你殺死了江清流，所以得到了 2 點聲望。)"NOR);
        ::die();
        return;
}

void normal_ai()
{
        /* 沒有exert ,則exert */
        if( !this_object()->query_skill_mapped("dagger") )
                command("exert sky-dagger");       

        /* 受傷時自我醫療 */ 
        if( this_object()->query("hp") < (this_object()->query("max_hp")/2) )
                heal();

        return;
}
 
void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(this_object()));

        /* 武器被打掉，則裝回去 */
        if( !this_object()->query_temp("weapon") ) 
                command("wield dagger");

        /* 受傷時會自我醫療  */
        if( this_object()->query("hp") + 1000 < (this_object()->query("max_hp")/4) )
                heal();

        /* 敵人->attack */

        command("exert sky-dagger");
        this_object()->start_busy(-2);

        return;
}
 
int accept_object(object who,object ob)
{
        object obj=this_object();
        if(ob->name()!="鷹羽"){
           command("? "+who->query("id"));
           command("say 在下並不需要這個東西。");
           return 0;
        } else {
           if( obj->is_busy() || obj->query_temp("meet_eagle") ){
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。");
             return 0;
           }
           
        message_vision("$N給了江清流一個"+ob->query("name")+"。\n",who);
//             obj->start_busy(10);
             obj->set_temp("meet_eagle",1);
             destruct(ob);
             call_out("meet_eagle",1,obj);
             return 1;
        }

}

void meet_eagle()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("meet_eagle");
      switch( i ) {
          case 1:
            command("say 啊! 這不是神鷹的鷹羽嗎?");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此鷹羽的？");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 2:
            message_vision(YEL"$N將得到鷹羽的過程告訴江清流。\n"NOR,me);
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 3:
            command("nod");
            command("soga");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 4:
            if(me->query_skill("sky-dagger") == 0) 
            {
            command("say 師父常說天嘯匕法可授有緣之人");
            command("say 如這位"+RANK_D->query_respect(me)+"不嫌棄, 就請這位"+RANK_D->query_respect(me)+"一觀!");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            } else {
              command("say 只可惜在下無以為報 ..請受在下一拜!");
              command("bow");
              obj->delete_temp("meet_eagle");
            }
            break;
          case 5:
            message_vision(YEL"江清流將天嘯匕法的基本心訣講解給$N聽.\n"NOR,me);
//            message_vision(HIY"(~~~~~一~~~~~個~~~~~時~~~~~辰~~~~~過~~~~~去~~~~~了~~~~~)\n"NOR,me);      
            message_vision(HIY"江清流說道:大俠果然是奇人, 這天嘯匕法竟能如此快的領悟!!\n"NOR,me);
            command("smile");
            for(int x=0;x<5;x++)
            me->add_skill("sky-dagger");
            obj->delete_temp("meet_eagle");
            break;
            }
} 



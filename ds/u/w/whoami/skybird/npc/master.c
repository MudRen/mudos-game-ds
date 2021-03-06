#include <ansi.h>
inherit NPC;
void heal();
int talk_action();
void accept_join(object me);

void create()
{
        set_name("趙長孫" , ({ "master chao","master","chao" }) );
        set("long",@long
傳出趙長孫乃是身高五尺, 滿面白鬍, 誰知今日一見卻不然, 其實趙長孫乃。
是身高四尺有餘, 且沒有白鬍, 不管如何, 總之, 趙長孫的醫術相當高明, 也
為他贏得了賽華陀的稱號。
long
);
        create_family( HIC "天梟冶藥" NOR ,7,"掌門");
        set("level",42);
        set("race","人類");
        set("age",65);
        set("nickname","白鬍華陀");
        set("adv_class",1);
        set("class1","skyowl");
        set("gender","男性");
        set("int",100);
        // 設定屬性分配表, 每一項的值在負9至正10之間
        // 而且四項的總和要剛好等於 20                  by shengsan
        set("guild_gifts",({2,3,8,7}));
        set("guild_skills",([
               "dodge"  : ({160,2,60}),
               "parry"  : ({160,2,60}),
               "dagger" : ({160,2,60}),
               "unarmed": ({160,2,60}),
        ])  );
        set("guild_spells",([
               "moxibustion" : ({999,1,5}),
        ])  );
        set_skill("dagger", 90);
        set_skill("sky-dagger", 90);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set("no_check_class",1);
        set("chat_chance", 10);
        set("chat_msg",({
                (:command("think"):),
        (:command("exert sky-dagger"):),
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (: command("exert sky-dagger") :),
                  (: command("acupuncture attack") :),
        }) );
        set("talk_reply",(: talk_action() :));
        setup();
        carry_object(__DIR__"eq/steel_dagger.c")->wield();
}

int talk_action()
{
     object me = this_player(), ob = this_object();
     int x = random(5);
     string *SkyPill =({"紅心丹(Red heart pill)","紫星丹(Purple star pill)","碧龍丹(Blue dragon pill)",
                        "綠清丹(Green pill)","還魂丹(Resurrect pill)",});
     string *SkyPillID = ({"red heart pill","purple star pill","blue dragon pill",
                        "green pill","resurrect pill",});
     if( !me->query("class1") && !me->query_temp("skyowl/SkyPillID") ){
     command("hmm");
     command("say 這位"+RANK_D->query_respect(me)+"是對行醫救人有興趣嗎？");
     command("say 這樣吧..如果你能找到"+SkyPill[x]+"..並把它拿來給我..");
     command("say 我就收你為徒，將我畢生所學淨授予你。"); 
     me -> add_temp("skyowl/SkyPillID", SkyPillID[x]);
     return 1;
     } else if( me->query("class1") == "skyowl" && me->query("level") == 25 ){
            command("say ...老夫已經沒有任何知識能夠傳授給你了");
            command("say 如果你還想專研醫學丹藥之術，就去找傳說中的醫仙毒王吧..");
            me -> add_temp("skyowl/skyowl_med", 1); 
            return 1;
            }
     return 0;
}

int accept_object(object who,object ob)
{
        string msg = who->query_temp("skyowl/SkyPillID");
        
        if( ob->query("id") != msg ) {
           command("? "+who->query("id"));
           command("say 在下並不需要這個東西。");
           return 0;
        } else {
        if(this_object()->is_busy() || this_object()->query_temp("no_give") ) {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。");
             return 0;
        } 
        message_vision("$N給了趙長孫一個"+ob->query("name")+"。\n",who);
             this_object()->set_temp("no_give",1);
             destruct(ob);
             accept_join(who);
             return 1;
        }

}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join"); 
        add_action("do_check_mark","apply");
}


void accept_join(object me)
{     
            command("hmm");
            command("say 那就照我們的約定，今天起你就是天梟弟子了。"); 
            message_vision(YEL"$N跪下來說道：師父！弟子必定遵照師父的教誨！\n"NOR,me);
            message_vision(HIY"趙長孫輕輕地拍拍$N的頭，並說道：好！好！..\n"NOR,me);
            message_vision(HIY"趙長孫說道：這是我派針灸用的銀針, 如今就給你一根吧!\n"NOR,me);
            new(__DIR__"obj/needle.c")->move(me);
            command("pat "+me->query("id"));
            command("smile");
            me->set("adv_class",1);
            me->set("class1","skyowl");
            me->create_family("天梟教", 8, "教眾");
            me->set("guild_rank","天梟教第八代教眾");
            me->delete_temp("skyowl/SkyPillID");
}

int do_skill_list(string arg)
{
        this_player()->set("no_check_class",1);    //暫時
        GUILDMASTER->do_skill_list(this_object(), this_player(), arg);
        GUILDMASTER->do_spell_list(this_object(), this_player(), arg);
        this_player()->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(), this_player(), arg);
        return 1;
}

int do_join(string arg)
{
     if(this_player()->query("class1")=="skyowl") return notify_fail("你已是天梟教教眾了。\n");
     if(arg!="skyowl") return notify_fail("你要拜入那一個門派?\n");
     talk_action();
     return 1;   
}

int do_advance(string arg)
{
        if (this_player()->query("family/family_name")=="天梟教") return GUILDMASTER->do_advance(this_object(), this_player(), arg);
        else return notify_fail("你不是天梟教眾。\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
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
CYN"\n  武林傳出了一則驚人的消息:\n\n\t救人無數的「白鬍華陀」趙長孫被"+ob->name(1)+"給做掉了。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
       tell_object(ob,HIW"(因為你殺死了趙長孫，所以得到了 1 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

void soldier_assist(object alert, object me)
{
        if(!living(this_object()) || is_fighting(me) ) return;
        kill_ob(me);
        me->fight_ob(this_object());
}

string guild_rank(object me)
{
        string rank;
        int lv = me->query("level")/10; // 將 rank 分為六個層次
        if( me->query("gender") == "女性" ) {
                switch( lv ) {
        // LV 10 ~ 19
                        case 1: rank = "初入醫道的江湖術士"; break;
                        case 2: rank = "小有名氣的藥術師";   break;
                        case 3: rank = "懸壺濟世的天梟弟子"; break;
                }
        } else {
                switch( lv ) {
                        case 1: rank = "初入醫道的江湖術士"; break;
                        case 2: rank = "小有名氣的藥術師";   break;
                        case 3: rank = "懸壺濟世的天梟弟子"; break;
                }
        }
        return rank;
}

void heal()
{
//     if(this_object()->query("hp") < this_object()->query("max_hp")/2)
//        command("exert bloodsky-force heal"); 要記得改 XD 
        
     if(this_object()->query("mp") < this_object()->query("max_mp") /2){
        this_object()->receive_heal("mp",100+random(50));
        message_vision("$N站起身來，舒展了筋骨，神情煥然一新。\n", this_object());
        } 
}

int do_check_mark(string arg)
{
        object me,ob,mark;
        me=this_player();
        if(me->query("class1")!="skyowl") return notify_fail("你不是天梟教眾。\n");
        if(mark=present("silver needle",me)) return notify_fail("你已經有「銀針」了。\n");
        ob=new(__DIR__"obj/needle");
        if(!ob->can_move(me))
        {
                destruct(ob);
                return notify_fail("你必須丟掉一些東西才拿的動喔！\n");
        }
        ob->move(me);
        message_vision("$N拿了一"+ob->query("unit")+ob->name()+"給$n。\n",this_object(),me);
        me->save();
        return 1;
}

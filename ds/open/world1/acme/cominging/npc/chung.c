#include <ansi.h>
#include <path.h>
inherit NPC;
void do_jail();
void create()
{
        set_name("林沖", ({ "lin chung","lin","chung" }) );
        set("level", 40);
        set("race","人類");
        set("gender","男性");
        set("title",HIG"禁軍"+HIR+"大元帥"NOR);
        set("age",50);
        set("long",
            "他就是名聞天下的禁軍大統帥，濃眉大眼、手掌有如蒲扇般的粗大，\n"
            "身裁壯碩，十分有威嚴，不愧\是禁軍大元帥。\n");
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
                (:do_jail:),
        }) );   
        set("chat_chance", 8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("sky_city_war", 1);
        setup();
        set_living_name("skycitywar");
        carry_object(__DIR__"eq/armor2")->wear();
        carry_object(__DIR__"eq/ring")->wear();
        carry_object(__DIR__"wp/risword")->wield();
}
void init()
{
        ::init();
        if(!this_object()->visible(this_player())) return;
        if(this_player()->query("level") > 9 && userp(this_player()) )
        {
          this_object()->kill_ob(this_player());
        }
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
        ob->add("popularity",2); //聲望
        tell_object(ob,HIW"(因為你殺死了林沖，所以得到了 2 點聲望)"NOR);
        ::die();
        //destruct(this_object());
        return;

}
void do_jail()
{
        int i,which;
        object *ppl;
        ppl = all_inventory(environment(this_object()));
        which = random(sizeof(ppl));
        switch(random(4)) {
                case 0: command("say 狗賊！！束手就擒吧！！"); break;
                case 1: command("say 反了反了！兄弟們﹐拿下這個匪徒！"); break;
                case 2: command("say 惡賊！！接我這招！！"); break;
                case 3: command("say 大伙們！拿下那個可疑的傢伙！"); break;
        }
        if( !living(ppl[which]) ) which = random(sizeof(ppl));
        if( !userp(ppl[which]) ) return;
        i = ppl[which]->query_skill("dodge");
        if( i > random(120))
        {
                message_vision(HIW"\n$N東躲西避，好不容易躲過了林沖的逮捕，卻也流了滿身大汗。\n"NOR,ppl[which]);
        }
        else {
                message_vision(HIW"\n$N毫無查覺後方林沖的來到，林沖將$N的雙手扣住，$N終究被林沖所捕。\n"NOR,ppl[which]);
message("world:world1:vision",HIR"\n  "+ppl[which]->name_id(1)+"大叫：放開我！你們抓錯人啦！！\n\n"+NOR,users(),ppl[which]);
                message_vision(HIW"\n$N的四周走出了二個官兵，將$N押進大牢裡了。\n"NOR,ppl[which]);
                ppl[which]->move(ACME_PAST+"cominging/superjail");
        }
}

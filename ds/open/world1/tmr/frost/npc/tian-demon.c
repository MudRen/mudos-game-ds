#include <ansi.h>

inherit NPC;
varargs int receive_damage(string type, int damage, object who);
void do_combat_attack();
mapping *combat_action = ({
        ([  "action":       "$N伸手一劃，數道慘綠色的光芒直射向$n的$l",
                "attact_type":  "bio",
                "damage_type":  "刺傷",
        ]),
});

/* 自定戰鬥訊息 */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}


void create()
{
        set_name("天妖" ,({"tian demon","demon", "_TIAN_DEMON_" }) );
        set("long",@LONG
「天妖」自磐古開天後，就和人類息息生存到現在，由於天妖是由眾
人類心中的邪惡念頭所累積團聚而成的，做惡的人越多，天妖的力量越是
強大、為害越大，幸好有佛、道的正派人士極力廣植善根，以絕人世間的
惡念，如此才能完全除去此妖，所謂「國之將亡、必有妖孽」，也是指天
妖這種千年禍害。
LONG
);
        set("age",200);
          set("race","evil");
        set("title","萬惡之首");
        set("level",60);
          set("race","evil");
        set("attitude", "aggressive");
        set("gender", "男性" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (:do_combat_attack():),
        }) );
        setup();
                set("default_actions", (: call_other, __FILE__, "query_action" :));
                set("actions", (: call_other, __FILE__, "query_action" :));

        set_living_name("_NPC_TIAN_DEMON_");
        set_temp("apply/armor",100);
          set_temp("apply/hit",120);


        carry_object(__DIR__"wp/devil-dagger")->wield();
          if( random(100) < 30)  
                carry_object(__DIR__"eq/tian-demon_cloak")->wear();
        else
                carry_object(__DIR__"eq/tian-demon_cloak2")->wear();

        carry_object(__DIR__"eq/thousandbone-shield")->wear();
}
// 戰鬥中的特攻
void do_combat_attack()
{
        object ob=this_object();
        object* targets;
        int i,j;
        
        targets=ob->query_enemy();
        if( sizeof(targets) > 1
	&& random(100)>70 
        )  {
        message_vision(HIM"\n$N張嘴吐出了一口渾濁而腥紅的霧氣.....\n"NOR,ob);
                for(i=0;i<sizeof(targets);i++)
                {
                        // 並不邪惡
                        if(targets[i]->query("evil")<400 ) {
                                tell_object(targets[i],CYN"\n(你心中善根堅定，並沒有受到霧氣的影響。)\n"NOR);
                                ob->add("evil",10);
                                continue;
                        }
                        j=random(sizeof(targets));
                        // 同一人..
                        if( targets[i]==targets[j] ) continue;
                        // 這二人已經在戰鬥了
                        if(targets[i]->is_fighting( targets[j]) ) continue;
                        // 讓這二人打起來...
                        tell_object(targets[i],HIR"\n(你吸入了少許\霧氣，竟觸動你心中的邪念，你開始想殺人了！！！。)\n" NOR);
                        targets[i]->fight_ob(targets[j]);
                        targets[j]->fight_ob(targets[i]);
                        message_vision(HIR "$N忽然開始攻擊$n！！\n" NOR,targets[i],targets[j]);             
                } // end for
         }
         else {
                // 補血
                if(ob->query("hp") < ob->query("max_hp")/2) {
                        message_vision(HIG"$N運起「醒魔大法」，身上受傷的血肉緩緩地瘉和了。\n"NOR,ob);
                        ob->receive_heal("hp",100+random(50) );  
                } else {
                        ob->attack();
                }
         } //end if
              command("wield dagger");
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage/=2;
                        message_vision(HIM "\n$N身前陡地出現一隻小妖，代$N消去了大半的傷害。\n" NOR,this_object());
                }
        if(damage<1) damage = 1;

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}

void die()
{
        object ob,energy=new(__DIR__"obj/energy");
        energy->move(this_object() );

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
 
                message("world:world1:vision",
        HIG"\n\t【道派消息】："+HIM"極邪兇殘的「天妖」本命星被"+ob->name(1)+"降伏了.....\n\n"+NOR
        ,users());
         ob->add("popularity",3); //聲望
         tell_object(ob,HIG"你得到三點聲望了。"NOR);
        ::die();
        return;
}


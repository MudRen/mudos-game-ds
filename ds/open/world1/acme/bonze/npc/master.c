#include <ansi.h>
inherit NPC;
void heal();
string ask_for_join();
void create()
{
        set_name("虛雲和尚", ({ "master bonze", "master", "bonze" }) );
        set("gender", "男性");
        set("age", 80);
        set("level",41);
        set("attitude", "peaceful");
        set("adv_class",1);
        set("class1","凌雲寺");
        set("apprentice_available", 10);
            set("guild_gifts",({3,7,3,7}));



        set("inquiry", ([
                "剃度" : "阿彌陀佛！善哉！善哉！施主若真心皈依我佛，請跪下(kneel)受戒。",
                "出家" : "阿彌陀佛！善哉！善哉！施主若真心皈依我佛，請跪下(kneel)受戒。",
                "剃度出家" : "阿彌陀佛！善哉！善哉！施主若真心皈依我佛，請跪下(kneel)受戒。",
                  "捐香油錢": "阿彌陀佛 ！施主有捐香油錢(lug)這個心意，老納真替你高興。",
        ]) );
        set("long",
                "他生得鶴髮道顏，貌相高古，仙風道骨的老人\n"
                "看上去至少也古稀以上年紀，但神情矍鑠，竟\n"
                "毫無老邁龍鐘之態。\n"
        );

        set("guild_skills",([
               "dodge" : ({140,3,60}),
               "parry" : ({130,3,80}),
               "staff" : ({120,3,80}),
               "wuchen-staff" : ({140,2,70}),
               "literate" : ({130,3,80}),
               "buddha-force" : ({135,3,90}),
               "quanyin-steps" : ({130,3,90}),
        ])  );

        set("guild_spells",([
               "recite-sutra" : ({140,3,80}),
        ]) );
        set("chat_chance", 10);
        set("chat_msg",({
                (:command("hmm"):),
               (:command("exert quanyin-steps"):),
              (:command("exert wuchen-staff"):),
           (: heal :),
        }) );

        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
              (:command("exert buddha-force armor"):),
                (:command("cast recite-sutra"):),
        }) );
 
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("staff",100);
        set_skill("literate",100);
        set_skill("force",100);
        set_skill("wuchen-staff",100);
        set_skill("quanyin-steps",100);
        set_skill("buddha-force",100);
        set_spell("recite-sutra",100);
        map_skill("staff","wuchen-staff");
        create_family("凌雲寺",4, "住持");
            set("addition_armor",100);
        set("evil",-50);
        setup();
        carry_object(__DIR__"wp/force-shake-staff")->wield();
}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_kneel","kneel");
        add_action("do_lug","lug");
}

int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);    //暫時
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")!="凌雲寺")
                return notify_fail("你不是凌雲寺和尚。\n");
        if( me->query("level")<=25 && !me->query("class2") )
                return  GUILDMASTER->do_advance(ob,me,arg);
        else
                return notify_fail("虛雲和尚似乎不理會你的請求。\n");
}


int do_join(string arg)
{
        int i;
        object ob, me;
        ob = this_object();
        me = this_player();
        if(arg != "凌雲寺") return notify_fail("這裡沒有這種門派耶....:P\n");
        {
          if( me->query("class1") ) return notify_fail("你已有門派了耶。....^_^\n");
          if( me->query("gender") != "男性" ) return notify_fail("虛雲和尚說道：阿彌陀佛！女施主，這裡是寺廟，請妳到尼庵去剃度吧。\n");
          tell_object(me,"虛雲和尚說道：阿彌陀佛！善哉！善哉！施主若真心皈依我佛，請先剃度出家吧。\n");
          me->set_temp("pending/join_bonze", 1);
          return 1;
        }
}
int do_kneel()
{
        string *prename = ({ "空", "明", "圓", "淨", "虛", "悟","方", "渡", "慧", "法" });
        string name, new_name;

        if( !this_player()->query_temp("pending/join_bonze") ) return 0;
        message_vision(
                HIC "$N雙手合十﹐恭恭敬敬地跪了下來。\n\n"
                        "$n伸出手掌﹐在$N頭頂輕輕地摩挲了幾下﹐將$N的頭髮盡數剃去。\n\n" NOR,
                this_player(), this_object() );
        name = this_player()->query("name");
        new_name = prename[random(sizeof(prename))] + name[0..1];
        command("say 從今以後你的法名叫做" + new_name + "。");
        command("smile");
        this_player()->set("guild_rank","凌雲寺第五代弟子");
        this_player()->delete_temp("pending/join_bonze");
        this_player()->set("adv_class",1);
        this_player()->set("class1","凌雲寺");
        this_player()->create_family("凌雲寺",5,"弟子");
        this_player()->set("name", new_name);
    this_player()->set("guild_gifts", query("guild_gifts") );

        return 1;
}
int do_lug(string arg)
{
        int i;
   object me,ob,coin;
        me=this_player();
        ob=this_object();
        if(!arg ) 
                return notify_fail("你要捐助多少香油錢呢？\n");
        if(sscanf(arg,"%d",i)!=1 ) 
                return notify_fail("你要捐助多少香油錢呢？\n");
        if(me->is_busy() )
                return notify_fail("你正忙著，沒有空捐香油錢。\n");
        if(me->is_fighting() )
                return notify_fail("你正忙著，沒有空捐香油錢。\n");
       if(!objectp(coin=present("coin",me) ) )
            return notify_fail("你身上沒有錢耶。\n");
     if(i > coin->query_amount() )
         return notify_fail("你身上的錢不夠耶。\n");
        message_vision("$N捐了"+(string)(i)+"文香油錢給$n\n",me,ob);
        command("smile");
         command("thank "+ me->query("id") );
          me->receive_money(-i);
          if(i > 99 && i < 501 )
        {
        command("say 這位施主大仁大德，讓老納為你調養身心，資補體健。");
          message_vision(GRN "\n$N臉上紫氣一現，重重一掌擊向$n背心！！\n"+HIR "$n「哇」地一聲吐了幾口鮮血。\n\n" NOR ,ob,me);
   me->receive_heal("hp",i/2);
   me->receive_heal("mp",i/3);
   me->receive_heal("ap",i/3);
           me->start_busy(i/20);
        }
        return 1;
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
CYN"\n  武林傳出了一則驚人的消息:\n\n\t慈悲為懷的凌雲寺方丈『虛雲和尚』終於敗給了"+ob->name(1)+"。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
        ::die();
        //destruct(this_object());
        return;
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        if( me->query("gender") == "女性" )
        {
                switch( lv )
                {
                        case 0: rank = "凌雲寺第五代弟子"; break;
                        case 1: rank = "凌雲寺第五代弟子"; break;
                        case 2: rank = "凌雲寺第五代弟子"; break;
                }
        }
        {
                switch( lv )
                {
                        case 0: rank = "凌雲寺第五代弟子"; break;
                        case 1: rank = "凌雲寺第五代弟子"; break;
                        case 2: rank = "凌雲寺之得道高僧"; break;
                }
        }
        return rank;
}
void heal()
{
     object obj;
     obj=this_object();
if(obj->query("hp") < obj->query("max_hp")/2)
{
      command("exert buddha-force heal");
}
}

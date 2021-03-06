#include <ansi.h>
inherit NPC;
void create()
{
        set_name("周顯宗",({"origami master","master"}));
        set("title",HIC"ＲＰＧ漫畫之神"NOR);
        set("nickname",HIW"摺紙工會會長"NOR);
        set("gender", "男性");
        set("long",@LONG
他是摺紙工會裡資深的理事長，這是遊龍俠重金聘來的摺紙教師。

        list    列出可學的技能
        train   訓練技能
        learn   學習法術
        join    加入工會
        apply   申請補發信物
        advance 升級或增加屬性

LONG
        );
        set("level",50);                
        set("age",40);
        set("adv_class",1);
        set("class1","origami");
        set("guild_skills",([   // 難度, 等級1可學到的技能等級倍率, 上限
                "dodge":({60,3,80}), 
                "gun":({60,3,80}),
                "combat":({50,3,80}),  
                "origami":({100,1,80}),  
                "doubleshoot":({80,2,90}),  
                "unarmed":({80,5,60}),
                "block":({40,3,70}), 
       ]) );
         set("guild_gifts",({10,5,-3,8}));
        setup();
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
     if(!query("no_join") || query("no_join")!=1)
        add_action("do_guild_join","join");
        add_action("do_check_mark","apply");
     if(!query("no_advance"))
        add_action("do_advance","advance");
}
int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // 避免列出檢查職業的訊息
        write("\n");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}
int do_guild_join(string arg)
{
        object ob, me;
        int i;
        ob = this_object();
        me = this_player();
        if( !arg && !me->query_temp("join_o") )
                return notify_fail("你想要加入什麼工會呀？(join origami)\n");
        if( me->query_temp("join_o") && !arg ) arg = "origami";
        if( strsrch(arg, "origami") == -1 || strsrch(arg, "不") > -1)
                return notify_fail("你想要加入什麼工會呀？(join origami)�)\n");
        message_vision("$N想加入「"+ HIM"" + arg + ""NOR+ "」。\n",me); 
        if( me->query("class1") )
                return notify_fail("你已是"+me->query("class1")+"的學徒了。\n");
        if( me->query("class1")=="origami" )
                return notify_fail("你已是摺紙工會的學徒了。\n");
        if( !me->query_temp("ojoin") && !me->query_temp("join_o") ) {
        command("whisper "+me->query("id")+" 嗯...如你所見...我們缺錢籌辦中...。");
        command("whisper "+me->query("id")+" 希望您能捐獻給我們五千元應急(donate 5000)。");
        me->set_temp("ojoin",1);
        add_action("do_donate", "donate");
        return 1;
        }
        else if( me->query_temp("ojoin") && !me->query_temp("join_o") ) {
                command("say 朋友，你決定了嗎？此事十分要緊，請快考慮。");
                add_action("do_donate", "donate");
                return 1;
        }
        else {
                command("pat "+me->query("id")); 
                command("thank "+me->query("id"));                            me->set("guild_rank","摺紙工會初級會員");
                message_vision("$N成為摺紙工會的會員。\n",me);
                me->set("class1","origami");
                me->set("adv_class",1);
                new("/u/k/kkeenn/origami/paper/paper.c")->move(me);
                write(WHT"周顯宗悄悄塞了一張破爛的透明紙給你。\n"NOR);
                return 1;
        }
}
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_advance(ob,me,arg);
        return 1;
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
                        case 0: rank = HIC"未來摺紙工會學徒"NOR; break;
                        case 1: rank = HIY"摺紙工會之女會員"NOR; break;
                        default: rank = HIM"摺紙工會摺紙戰士"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"未來摺紙工會學徒"NOR; break;
                        case 1: rank = HIY"摺紙工會之男會員"NOR; break;
                        default: rank = HIM"摺紙工會摺紙戰士"NOR;
                }
        }
        return rank;
}
int do_donate(string arg)
{
        object me;
        int i;
        me = this_player();
        if( !arg )
        return notify_fail(HIG"Computer Type Out 'How much money do you want to donate ?'。\n"NOR);
        if(sscanf(arg,"%d",i)!=1 ) 
        return notify_fail(HIG"Computer Type Out 'How much money do you want to donate ?'。\n"NOR);
        if( i < 5000 )
        return notify_fail("Computer Type Out 'The low money limit is 5000 !'。\n");
        if(me->query("bank/future") < i )
        return notify_fail("Computer Type Out 'Sorry, you don't have "+i+" future coco.'。\n");
        message_vision("$N donated "+i+" coco to the Origami club！\n"NOR,me);
        me->add("bank/future",-i);
        me->set_temp("join_o",1);
        return 1;
}
int do_check_mark(string arg)
{
        object me,ob,mark;
        me=this_player();
        if(me->query("class1")!="origami")
                           return notify_fail("你並沒有參加摺紙工會�。\n");
        if(mark=present("none paper",me))
                           return notify_fail("你已經有紙類信物了。\n");
        if(mark=present(me->query("family/id")+" paper",me))
                           return notify_fail("你已經有紙類信物了。\n");       
        if(mark=present("armor",me))
                           return notify_fail("你已經有紙類信物了。\n");   
   if(!me->query("family"))
{
        ob=new("/u/k/kkeenn/origami/paper/paper.c");
}
else
{
        ob=new("/u/k/kkeenn/origami/paper/paper2.c");
}
        if(!ob->can_move(me))
        {
                destruct(ob);
                return notify_fail("你必須丟掉一些東西才拿的動此摺紙。\n");
        }
        ob->move(me);
        message_vision("$N拿了一張"+ob->name()+"給$n。\n",this_object(),me);
        me->save();
        return 1;
}

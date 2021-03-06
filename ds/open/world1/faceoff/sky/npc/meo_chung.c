#include <ansi.h>
inherit NPC;
void create()
{
    set_name("苗杖七",({"meo chung chi","chi","meo",}));
    set("long",@LONG
他是苗家村的宗族長，已經高齡七十餘歲。人稱三絕苗，分
別為「道術、武術、以及十萬大山一帶的地下勢力控制權」。不
過他現在看起來一副病懨懨的樣子....
LONG
         );

    set("attitude", "peaceful");
    set("age",73);
    set("nickname",CYN"宗族長"NOR);
    set("evil",-10);
    set("gender","男性");
    set("level",30);
    set("str",100);
    set("con",100);
    set_skill("sword", 100);
    set("chat_chance",10);
    set("chat_msg", ({"苗杖七遺憾的說：看來那件事我是沒辦法完成的了....\n",
                         }) );
    setup();
}

int talk_action(object me)
{
    object book;
    if(!book=me->query_temp("notebook")) return 0;
    if(random(2))
    {
        if (me->query("int") > 40)
        {
            command("think");
            command("nod");
            command("say 看來小老弟的智慧也許\能夠避去這場大難....");
            command("say 不知道小老弟能否答允老夫幫(givehand)這個忙?");
        }
        else
        {
            command("say 老夫一點小事不敢麻煩老弟....^^");
        }
    }
    return 1;
}

void init()
{
    add_action("do_givehand","givehand");
}
int x=0;
int do_givehand(string arg)
{
    object me,where1,p;
    string a;
    me = this_player();
    where1 = load_object(__DIR__"ten42");
    if( me->is_busy() )
        return notify_fail("你還在忙！\n");
    if( me->is_fighting() )
        return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
    if( !arg || sscanf(arg, "%s", a )!=1 )
        return notify_fail("指令格式: givehand <某人>\n");
    if( a!="meo" && a!="meo chung chi" && a!="chi")
        return notify_fail("你要幫誰忙?\n");
    if( query_temp("give_hand") == 0)
    {
        message_vision("苗杖七緩緩說道: 百年前十萬大山是仙人與神獸的戰場...\n",me);
        message_vision("苗杖七繼續說道: 而仙人略勝一籌, 但卻沒有能力將神獸摧毀, 因此將神獸封印在十萬大山各山峰下 \n",me);
        message_vision("苗杖七繼續說道: 如今封印漸漸減落, 苗家歷代祖先都用己身的血印將封印再度加強.\n",me);
        message_vision("苗杖七繼續說道: , 如此方才勉強將神獸封印住, 但老夫不學無術, 血印之術並沒有流傳下來,\n",me);
        message_vision("苗杖七繼續說道:  因此希望老弟將此令帶給滅骨峰上的高人, 如此也許\尚有一線希望....\n",me);
        message_vision(HIC"苗杖七給了$N三面令牌. \n"NOR,me);
        p=new(__DIR__"obj/wood_plate");
        p->move(this_player());
        p=new(__DIR__"obj/wood_plate");
        p->move(this_player());
        p=new(__DIR__"obj/wood_plate");
        p->move(this_player());
        set_temp("give_hand",1);
    }
    else
    {
        message_vision("苗杖七道: 多謝老弟，但剛才已經有人取走青木令了...！ \n",me);
    }
    return 1;

}

int accept_object(object who,object ob)
{
    object p;
    if(ob->name()!="九轉回魂丹")
    {
        command("? "+who->query("id"));
        return 0;
    }
    else {
        if( is_busy() )
        {
            command("whisper "+who->query("id")+" 請你等一下。");
            return 0;
        }
        message_vision("$N給了苗杖七一個"+ob->query("name")+"。\n",who);
        start_busy(10);
        set_temp("kill_wang",1);
        destruct(ob);
        call_out("kill_wang",1);
        return 1;
    }

}
int x=0;

void kill_wang()
{
    int i;
    object me,item,p,n;
    me=this_player();
    i = query_temp("kill_wang");
    switch( i ) {
    case 1:
        message_vision("苗杖七愣了一愣，隨即轉頭望向$N!\n",me);
        command("say 其實生死還不是天地的循環，苗芃這孩子又何必如此看不開.....");
        command("shake");
        set_temp("kill_wang",i+1);
        call_out("kill_wang",3,me);
        break;
    case 2:
        command("say 想來也是老弟為苗芃找來這些藥材的吧?");
        set_temp("kill_wang",i+1);
        call_out("kill_wang",3,me);
        break;
    case 3:
        command("think");
        command("say 老弟總是一番心意，如果沒有些表示，老夫也被那些小輩小覷?");
        command("hoho");
        set_temp("kill_wang",i+1);
        call_out("kill_wang",3,me);
        break;
    case 4:
        //    if(x == 1)
        if( query_temp("gived") )
        {
            message_vision(HIG"苗杖七對著$N念念有詞，忽然一道綠光從$N身上閃過!!\n"NOR,me);
            command("say 老夫垂暮之年，這些東西留著也是沒用了，老弟拿去使使吧!");
            message_vision(HIW"苗杖七給了$N一雙護腕\n"NOR,me);
            p=new(__DIR__"eq/white_wrists");
            p->move(me);
            command("smile");
            delete_temp("kill_wang");
            me->set_temp("bless",1);
            set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
        }
        else
        {
            message_vision(HIG"苗杖七對著$N念念有詞，忽然一道綠光從$N身上閃過!!\n"NOR,me);
            command("say 老夫垂暮之年，這些東西留著也是沒用了，老弟拿去使使吧!");
            message_vision(HIC"苗杖七給了$N一雙護腕\n"NOR,me);
            p=new(__DIR__"eq/wind_wrists");
            p->move(me);
            command("smile");
            delete_temp("kill_wang");
            set_temp("gived",1);
            x = 1;
            me->set_temp("bless",1);
            set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
        }
        break;
    }
}

void reset()
{
    delete_temp("give_hand");
    set("chat_msg",({
                            "苗杖七遺憾的說：看來那件事我是沒辦法完成的了....\n",
                    (:command("sigh"):),
                                }) );
    return;
}


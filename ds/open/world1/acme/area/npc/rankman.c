#include <ansi.h>
inherit NPC;
void create()
{
        set_name("知無不解" , ({ "give me rank","rank" }) );
        set("long",@long
他是提供神武教沒有==Rank 資訊==的人，沒有rank找他要
就對了,跟他說話或許能進一步得到消息。
long
);
        create_family( "神武教",3,"教徒");
        set("level",10);
        set("race","人類");
        set("age",20);
        set("nickname","宇宙先知");
        set("adv_class",1);
        set("class1","神武教");
        set("no_fight",1);
        set("gender","男性");
        set("talk_reply","若你是神武教，而且想要RANK就->say 我要RANK啦");
        setup();
}
void init()
{
        add_action("do_say","say");
}
int do_say(string arg)
{
    int lv;
    string rank;
    object me;
    me=this_player();
    if(arg == "我要RANK啦" && me->query("class1") == "神武教" )
    {
        command("say 好好！！我幫你改改！");
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        if( me->query("gender") == "女性" )
        {
                switch( lv )
                {
                        case 0: rank = "神武教第三代教徒"; break;
                        case 2: rank = "神武教之烈焰破空"; break;
                        case 3: rank = "神武教之火劍雙絕"; break;
                        case 4: rank = "神武教火雲女劍俠"; break;
                        default: rank = HIC"神武教之毀天滅地"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "神武教第三代教徒"; break;
                        case 1: rank = "神武教第三代教徒"; break;
                        case 2: rank = "神武教之烈焰破空"; break;
                        case 3: rank = "神武教之火劍雙絕"; break;
                        case 4: rank = "神武教之火雲劍俠"; break;
                        default: rank = HIC"神武教之毀天滅地"NOR;
                }
        }
        me->set("guild_rank",rank);
     }

}

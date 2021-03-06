#include <ansi.h>
#include <path.h>

#define GOD_DIR "/u/m/moonhide/westarea/"  // Add by -Acme-
inherit ITEM;

void open_war(object me,object ob);
void end_war();

string *god=({"ba","lin","ean","mon","sha",
          "poo","dang","unin","liu"});

string *place=({"room2","room1","startroom","room3",
        "room4","room5","room6","room7","room8",
        "room9","room10","room11","room12","room13",
        "room14","room15","room"});

int query_god();  

void create()
{
        set_name(HIY"無  上  至  尊  像"NOR,({"god-king statue","statue","god"}) );
        set_weight(5000000); 
        set("long","一尊十尺長的翡翠雕像, 整尊雕像凹凹凸凸, 看來年代已久遠了。\n");
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","尊");
                set("no_get",1);
                set("no_sac",1);
                set("value", 90000);
        }
        setup();
}

void init()
{
        add_action("do_firing","firing");
}

int do_firing(string arg)
{
        object me,ob,god,torch;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="statue") return 0;
        if(!objectp(torch=present("torch",me) ) )
                return notify_fail("你身上沒有火把。\n");
        if( ob->query("open_war") || query_god() )
                return notify_fail("無數的天魂還在雲端上。\n");

        destruct(torch);
        message_vision(HIW"$N點然"HIR"火把"HIW"，往無上至尊像丟了過去，至尊像瞬間透紅 . . . \n"NOR,me);
        message_vision(HIY"\n\n一道道的光芒從天上打了下來 . . .\n"NOR,me);
        ob->set("open_war",1);
        call_out("open_war",3,me,ob);
        return 1;
}

void open_war(object me,object ob)
{
        int i;
        object g;

        if( !ob->query("open_war") ) return;
        message("world:world1:vision",
HIR"\n         "+me->query("name") +HIW "解開了無上至尊像身上的秘密.......\n\n"
HIC"        【~霸魂~】: 眾神聽令 ! ! 將雲端上的人.....\n\n\n"
HIR"         通        通        格        殺 ! !\n\n" NOR
,users() );
//        g=new(__DIR__"pill" );  mark by -Acme-
        for(i=0;i<=12;i++)
        {
                g=new(__DIR__"pill"   );
                g->move(GOD_DIR+place[random(sizeof(place))]);   // Add by -Acme-
                g=new(__DIR__+god[random(sizeof(god))]);   // Add by -Acme-
                g->move(GOD_DIR+place[random(sizeof(place))]);   // Add by -Acme-
        }

        call_out("end_war",180);
        return;
}

void end_war()
{
        object god;

        if( query_god() )
                call_out("end_war",30);
        else {
                message("world:world1:vision",
HIC"\n\n\t         整片雲端的戰聲...傳遍了整個世界 \n\n"NOR
HIW"       .................眾天魂死傷慘重.............\n\n" NOR 
HIG"       ................隨時有撤兵的可能............\n\n"NOR                ,users() );
                this_object()->set("open_war",0);
        }       
                return;
}

int query_god()
{
        object god;

        while( objectp(god=find_living("god-war")) )
        {
                if( !environment(god) )
                {
                        destruct(god);
                        god = 0;
                }
                else break;
        }

        if( objectp(god) ) return 1;
        else return 0;
}


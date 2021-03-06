// Edit By Tmr -2002/1/25-

#include <ansi.h>
#include <path.h>

// 解war 的人數
#define MaxUser 4

inherit ITEM;

nosave object *JoinUser=({});


int query_buddha();
int open_war();
/* 如來佛登場*/
void end_war();
/* 結束war*/
void end_war2();
/* 凌雲派跪下... */
void kneel_bonze()
{
        int i=0;
        object* ob=users();
        for(i=0;i<sizeof(ob);i++)
        {
                if( ob[i]->query("class1")!="凌雲寺" ) continue;
                message_vision(HIG "$N「噗咚」一聲跪了下來，虔誠恭敬大聲說道：「弟子恭迎如來佛祖降臨！！」\n" NOR,ob[i]);
        }

}

void open_sun() {
        "/adm/daemons/event/bonze.c"->trigger_event();
}

void checkuser();

void create()
{
        set_name(HIY "如來金佛像" NOR ,({"rulaifo statue","statue"}) );
        set_weight(200000);
        set("long",@LONG
在你眼前的是一尊高十數丈高的金佛像，呈如意坐姿，法相尊嚴，你
站在佛像的面前，頂多只能抵到佛像的膝蓋處。如來佛像透著日光照射，
宛如如來現世的神蹟，你在萬丈光芒之中，似乎就像是如來佛現身正對著
你講述佛法，導正引善。你的心中受到感應，雙腳似乎就要跪下了。
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","尊");
                set("no_get",1);
                set("no_sac",1);
                set("value",20000);
        }
        setup();
}

void init()
{
        object ob;
        object me=this_player();
        if( objectp(ob=present("_BUDDHA_WAR_BOOK_",me) ) 
                && ob->query("owner_user")==me->query("id")     )
                tell_object(me,HIY "你身上的般若心經一陣抖動，似乎正慫恿著你參加(join)試驗。\n" NOR);
        add_action("do_join","join");

}

int do_join(string arg)
{
        object book;
        object me=this_player();
        int i;
        if(arg!="試驗")         return 0;
        if(me->is_fighting() || me->is_busy() ) 
                return notify_fail("你正忙著，沒有空參加試驗。\n");
        
        if( !objectp(book=present("_BUDDHA_WAR_BOOK_",me) ) )
                return notify_fail("你並沒參加試驗的資格。\n");
    if( book->query("owner_user")!=me->query("id")      )
                return notify_fail("你並沒參加試驗的資格。\n");
        if(     this_object()->query("open_war") || query_buddha() )
                return notify_fail("如來佛祖的試驗已經在進行中了。\n");
        
        
        message_vision(HIW "$N拿起般若心經，恭敬地向佛像叩了幾個響頭，要求參加試驗。\n" NOR,me);
        checkuser();
        for(i=0;i<sizeof(JoinUser);i++)
                if(JoinUser[i]==me)
                        return notify_fail("你已經參加試驗了。\n");

        JoinUser+=({me});
        message_vision("$N被准許\參加試驗，目前共有" + sizeof(JoinUser) +"個人參加。\n",me);
        destruct(book);

        checkuser();
        // 人數夠了，開War
        if(sizeof(JoinUser)==MaxUser)
        {
                set("open_war",1);
                message_vision(HIY "如來金佛像發出一陣十分耀眼的光芒......\n" NOR,me);
                call_out("open_war",3);
        }
        return 1;
}

int open_war()
{
        int i;
        object g;
                string username="";

                set("open_war",1);
                //放 四金剛Npc
                // 不動
                g=new(__DIR__"npc/buddha1");
                g->move(__DIR__"summit2");
                // 大力
                g=new(__DIR__"npc/buddha3");
                g->move(__DIR__"summit3");
                //怒意
                g=new(__DIR__"npc/buddha2");
                g->move(__DIR__"summit5");
                //拈花
                g=new(__DIR__"npc/buddha4");
                g->move(__DIR__"summit4");

                 // 四個npc 都放在同一格
                  g=new(__DIR__"npc/buddha1");
                  g->move(__DIR__"summit1");
                  g=new(__DIR__"npc/buddha2");
                  g->move(__DIR__"summit1");
                  g=new(__DIR__"npc/buddha3");
                  g->move(__DIR__"summit1");
                  g=new(__DIR__"npc/buddha4");
                  g->move(__DIR__"summit1");

                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit2");
                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit3");
                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit4");
                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit5");
                   g=new(__DIR__"npc/buddha5");
                   g->move(__DIR__"summit6");



                for(i=0;i<sizeof(JoinUser);i++)
                        username+=JoinUser[i]->query("name") + " ";
        message("world:world1:vision",
  HIY "\n\n位在凌雲峰頂上的" +username + "等四人恭敬的宣佛號道：\n\n" + HIW

+"\t「生 死 熾 然 ， 苦 惱 無 量；\n"
+"\t  發 大 乘 心 ， 普 濟 一 切；\n"
+"\t  願 代 受 眾 生 無 量 苦，\n"
+"\t  令 諸 眾 生 畢 竟 大 樂。」\n"
+HIM "\n\n如來佛祖留下的苦難驗自此開始了。\n\n" NOR
        ,users() );

                call_out("end_war",10);
        return 1;
}

/* 如來佛祖　登場 */
void end_war()
{
        object g;
        object buddha;
                checkuser();
                //參加人數不夠
                if(sizeof(JoinUser)<MaxUser) 
                {
                message("world:world1:vision",
                HIC "\n【佛門消息】凌雲峰頂上進行中的苦難驗因為試驗者的逃避而中斷了！！\n\n" NOR
                                ,users() );
                        set("open_war",0);
                        JoinUser=({});
                                 // 清除所有War Npc
                                while( objectp(buddha=find_living("buddha-war-jingang")) )
                                {
                                        if( !environment(buddha) )
                                        {
                                                    destruct(buddha);
                                                        buddha = 0;
                                                        continue;
                        }
                                tell_room(buddha,HIW "天上射下一道白色光芒包住了"+buddha->query("name")+"，隨即消失在你眼前！！" NOR);
                                destruct(buddha);
                                buddha = 0;
                                } // end while
              return;
                        } // end if

                        if( query_buddha()  )
                          call_out("end_war",30);
                        else {
                        /* 如來佛祖　登場 */
                        g=new(__DIR__"npc/rulaifo");
                        g->move(__DIR__"summit1");

                message("world:world1:vision",
                 HIG "\n\n【佛門消息】凌雲峰頂上佛光萬丈，大慈大悲的如來佛祖現身人世間了！！\n\n" NOR 
                ,users() );
                        // 讓 凌雲派 的弟子跪下恭迎
                        kneel_bonze();
                call_out("end_war2",10);
                        }       
        return;
}

void end_war2()
{
        object buddha;
                object book;
                int i;
        
                checkuser();
                //參加人數不夠
                if(sizeof(JoinUser)<MaxUser) 
                {
                message("world:world1:vision",
                HIC "\n【佛門消息】凌雲峰頂上進行中的苦難驗因為試驗者的逃避而中斷了！！\n\n" NOR
                                ,users() );
                        set("open_war",0);
                        JoinUser=({});
                        // 清除所有War Npc
                while( objectp(buddha=find_living("buddha-war-jingang")) )
                    {
                if( !environment(buddha) )
                {
                        destruct(buddha);
                        buddha = 0;
                                                continue;
                }
                                tell_room(buddha,HIW "天上射下一道白色光芒包住了"+buddha->query("name")+"，隨即消失在你眼前！！" NOR);
                                destruct(buddha);
                                buddha = 0;
                        }
                        return;
                }

                if( query_buddha()  )
                          call_out("end_war2",30);
        else {
                message("world:world1:vision",
    HIG"\n\n【佛門消息】「菩薩清涼月，常遊畢竟空，眾生心垢淨，菩提月現前。」\n" 


+HIC "\n\t凌雲峰頂上的苦難驗完滿結束了！！\n\n" NOR
                        ,users() );
                                // 降低試驗者的邪惡值
                                for(i=0;i<sizeof(JoinUser);i++)
                                {
                                        if(!JoinUser[i]) continue;
                                        book=new(__DIR__"npc/obj/jingang-book");
                                        tell_object(JoinUser[i],HIB "經過如來佛的洗禮，你的心中對於為善的念頭又更深一層了。\n" NOR);
                                        tell_object(JoinUser[i],"你的身上忽然多了一本手卷！？\n" NOR);
                                        book->move(JoinUser[i]);
                                            JoinUser[i]->add("evil",-300);

                                }
                set("open_war",0);
                                JoinUser=({});
                 // 自然奇觀：凌雲峰頂日出
                  call_out( "open_sun", 60 + random(30));
        }       
        return;
}

int query_buddha()
{
        object buddha;

        while( objectp(buddha=find_living("buddha-war-jingang")) )
        {
                if( !environment(buddha) )
                {
                        destruct(buddha);
                        buddha = 0;
                }
                else break;
        }

        if( objectp(buddha) ) return 1;
        else return 0;
}

void checkuser()
{
        int i;
        for(i=0;i<sizeof(JoinUser);i++)
                if( !JoinUser[i] )      JoinUser-=({JoinUser[i]});
}


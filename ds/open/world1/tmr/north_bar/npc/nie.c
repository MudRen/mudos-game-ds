#include <ansi.h>
#include <net/dns.h>
inherit NPC;

int COUNT = 0;

void do_teach();

void create()
{
      set_name("聶神父",({"nie priest", "priest", "nie"}) );
        set("long",@LONG
聶神父是西方人，長的金髮黃眼，雖然年齡快七十歲，但
還是神彩奕奕。聶神父在北蠻村定居有好幾年了，他在這兒主
要的工作是要宣揚聖經，由於聶神父講的都是洋水，你讀書識
字必須要到一定程度，才可以跟他學習。
LONG       
);
        set("title","傳道士");
        set("age", 60+random(10));
        set("level",1);
        set("gender","男性");
        set("race","人類");
        set("no_kill",1);
        set("chat_chance", 15);
        set("chat_msg",({ 
  (: do_teach :),
  (: do_teach :),
  (: command,"yawn" :),
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
}));
        setup();
    carry_object(__DIR__"obj/bible")->wield();
}

void do_teach()
{
        object ob,*s;
        string *a,arg;
        int j;

         a = ({
                "In the beginning God created the heaven and the earth.",
                                "And the earth was without form, and void;",
                                "And darkness was upon the face of the deep. And the Spirit of God moved upon the face of the waters",
                                "And God said, Let there be light: and there was light.",
                                "And God saw the light, that it was good: and God divided the light from the darkness.",
                                "And God called the light Day, and the darkness he called Night.",
                                "And the evening and the morning were the first day",
                                "And God said, Let there be a firmament in the midst of the waters, and let it divide the waters from the waters.",
                                "And God made the firmament, and divided the waters which were under the firmament from the waters which were above the firmament; and it was so.",
                                "And God called the firmament Heaven. And the evening and the morning were the second day.",
                                "And God said, Let the waters under the heaven be gathered.",
                });

        if( COUNT >= sizeof(a) ) {
                COUNT = 0;
                arg = "今天先念到這，下回待續";
        }
        else arg = a[COUNT];

        COUNT++;
        message_vision(HIG"$N唸道："+arg+"\n"NOR,this_object());

        s = all_inventory(environment(this_object() ));

        for(j=0;j<sizeof(s);j++)
        {
                if(s[j]->query_temp("Confucius") )
                {
                        if( s[j]->query_temp("netdead") == 1 ) continue;
                        // 斷線的人不能跟著讀書...add by -Acme-
                        if( s[j]->query_skill("literate", 1) < 100 )
                        ob=present("_BIBLE_BOOK_", s[j]);
                        if( objectp(ob) ) // 有聖經，讀書效果比較好
                        {
                                // 拿聖經會跟著念
//                                  message_vision(NOR""+YEL"$N^X^R^U^[^I^@^YD^AG"+arg+"\n"NOR,sj )
                                s[j]->improve_skill("literate", 5 + random( s[j]->query_int()/5 + 10));
                        }
                        else
                                s[j]->improve_skill("literate", random( s[j]->query_int()/9 + 5 ));

                }
        }


        return;
}

void init()
{
        if( this_player()->query_temp("Confucius") )
                this_player()->delete_temp("Confucius");
        add_action("do_sit","sit");
}

int do_sit()
{
        object me;
        me=this_player();

        if( me->query_temp("Confucius"))
          return notify_fail("你已坐下來專心聽講了。\n");
        if( me->is_fighting() )
                return notify_fail("你正忙著打架，沒空聽課！\n");
        if( me->is_ghost() )
                return notify_fail("都死了，還讀什麼書..:P！\n");
        if( me->is_busy() )
                return notify_fail("你正忙著，沒有空聽課。\n");
        if( me->query_skill("literate",1) > 100 )
                return notify_fail("這裡已經沒辦法再教你什麼了。\n");
                if( me->query_skill("literate",1) < 60 )
              return notify_fail("你讀書識字還不怎麼熟練，無法聽懂聶神父的話。\n");

        if(me->query("class1")=="凌雲寺")
                message_vision("$N念了聲「阿彌陀佛，罪過罪過」，在角落找了個不起眼的位子坐下。\n",me);
        else
                message_vision("$N在旁找了個位子坐了下來，專心讀書。\n",me);
        me->set_temp("Confucius",1);
        return 1;
}



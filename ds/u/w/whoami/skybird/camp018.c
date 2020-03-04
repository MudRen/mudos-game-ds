#include <ansi.h>
inherit ROOM;

void callmob();
void end_war();
void start_war();

string *soldier=({"sword_soldier","pike_soldier","axe_soldier","leader","leader2"});

void create()
{
        set("short", "固山寨廚房");
        set("long", @LONG
這裡面還算乾淨，至少不會過於骯髒，數個的大灶中的木材
不停批哩趴啦的發出聲音，這裡被大釜中滾滾冒出的熱氣給弄得
煙霧瀰漫，你似乎可以猜出今天的主菜是什麼。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"camp019",
]));
        set("objects", ([
       __DIR__"mob/soldier_cook" : 1,
                ]));

        set("light",1);
        set("no_clean_up", 0);
        setup();
}

void start_war()
{
        int i,x;
        object g;
        x = random(24);
        if(x<3) x=3;
//小嘍囉(bandit's lackey)  -> 15 隻
//悍匪(bandit)             -> 10 隻
//土匪(brigand)            ->  7 隻
//小頭目(ringleader)       ->  5 隻
//----------------------------------
//合計(total)              -> 37 隻

/*
                message("world:world1:vision",
        HIW"\n\t十萬山寨群賊一哄而散，整座山寨宛若空城•\n\n"  NOR
                ,users() );
*/

        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[0]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        }
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[1]);
        g->move(__DIR__+"camp0"+x); 
        g->set_temp("auto_kill"); 
        } 
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[2]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        } 
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[3]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        } 
        for (i=0;i<=3;i++)
        {
        g=new(__DIR__+"mob/"+soldier[4]);
        g->move(__DIR__+"camp0"+x);
        g->set_temp("auto_kill"); 
        } 
     call_out("end_war",40);
     return;
}

void end_war()
{
        object npc;
        object e,s,n,w;
        if(objectp(npc=find_living("Ten-mount_soldier") ) )
        {
                 if(!environment(npc)) destruct(npc);
                  call_out("end_war",30,0);
        }
        else { 
/*                message("world:world1:vision",
        HIW"\n\t十萬山寨群賊一哄而散，整座山寨宛若空城•\n\n"  NOR
                ,users() );
*/
          this_object()->delete("Ten-mount_soldier");
        }
return;
}


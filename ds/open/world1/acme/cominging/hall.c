#include <ansi.h>
#include <path.h>
inherit ROOM;
void callmob1();
void callmob2();
void callmob3();
void callmob4();
void end_war();
void start_war();


string *place=({"street3","street4","street5","street6","street2",
                "plaza","plaza1","plaza2","plaza3","plaza4",
                "pathway1","pathway2","smallway","ndoor","edoor","wdoor","sdoor" });
string *place2=({"bigwall","door2","door1","passage1","passage2","passage3",
                "room2","room2","bigdoor","way1","way2","way3","yidoor",
                "path1","path2","path3","path4","path5","path6","path7",
                "path8","path9","hall"});
string *garrison=({"soldier","general","lu","gu","chung",
                   "general2","chief","chief2","leader","lord"});


void create()
{
        set("short", "公堂");
        set("long", @LONG
這裡就是天城的公堂了，公堂上坐著縣老爺，公堂的二旁站著一
排的官兵，手上拿著板子和牌子，你可以看見牌子上寫著「威武」、
「肅靜」，看來你得乖乖的別鬧事，也不能在這裡大喊大叫，否則會
被罰的！
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"path3",
]));
set("objects",([
     __DIR__"npc/gou.c" : 1,
    __DIR__"npc/garrison.c" : 4,
]) );
        set("light",1);

        setup();
}

void start_war()
{
        int i;
        object g;
//士兵(soldier)  -> 15 隻
//牙將(general)  -> 10 隻
//裨將(general2) ->  7 隻
//百夫長(chief)  ->  5 隻
//千夫長(chief2) ->  4 隻
//總兵(leader)   ->  3 隻
//把總(lord)     ->  2 隻
//成陸(lu)       ->  1 隻
//成谷(gu)       ->  1 隻
//林沖(chung)    ->  1 隻
//------------------------
//合計(total)    -> 49 隻

        for (i=0;i<=10;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[0]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        } //天城裡的-->士兵(soldier)

        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[0]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//衙門裡的-->士兵(soldier)

     call_out("callmob1",20);
//   call_out("end_war",60);
    return;
}
void callmob1()
{
        int i;
        object g;
        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[1]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//天城裡的-->牙將(general)

        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[1]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//衙門裡的-->牙將(general)

     call_out("callmob2",20);
     return;       
}
void callmob2()
{
        object g;
        int i;
        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[5]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//天城裡的-->裨將(general)

        for (i=0;i<=2;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[5]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//衙門裡的-->裨將(general)

     call_out("callmob3",20);
     return;
}
void callmob3()
{
        object g;
        int i;

        for (i=0;i<=3;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[6]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//天城裡的-->百夫長(chief)

        for (i=0;i<=2;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[6]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//衙門裡的-->百夫長(chief)

     call_out("callmob4",20);
     return;
}
void callmob4()
{
        object g;
        int i;
        for (i=0;i<=3;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[7]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//天城裡的-->千夫長(chief2)

        g=new(ACME_PAST+"cominging/npc/"+garrison[7]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        //衙門裡的-->千夫長(chief2)

        for (i=0;i<=2;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[8]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//天城裡的-->總兵(leader)

        g=new(ACME_PAST+"cominging/npc/"+garrison[8]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        //衙門裡的-->總兵(leader)

        g=new(ACME_PAST+"cominging/npc/"+garrison[9]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //天城裡的-->把總(lord)

        g=new(ACME_PAST+"cominging/npc/"+garrison[9]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        //衙門裡的-->把總(lord)

        g=new(ACME_PAST+"cominging/npc/"+garrison[2]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //天城裡的-->成陸(lu)

        g=new(ACME_PAST+"cominging/npc/"+garrison[3]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //天城裡的-->成谷(gu)

        g=new(ACME_PAST+"cominging/npc/"+garrison[4]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //天城裡的-->林沖(chung)
     call_out("end_war",500);
     return;
}
void end_war()
{
        object npc;
        object e,s,n,w;
        if(objectp(npc=find_living("skycitywar") ) )
{
                 if(!environment(npc)) destruct(npc);
                  call_out("end_war",30,0);
        }
        else {
                message("world:world1:vision",
        HIY   "\n     禁軍被殺得潰不成軍，紛紛逃命去，也開啟了城門。\n\n"  NOR
                ,users() );
//            find_object(ACME_PAST+"area/ndoor")->unlock_door("north",1);
//            find_object(ACME_PAST+"area/sdoor")->unlock_door("southdown",1);
//            find_object(ACME_PAST+"area/edoor")->unlock_door("east",1);
//            find_object(ACME_PAST+"area/wdoor")->unlock_door("southwest",1);
        n=find_object(ACME_PAST+"area/ndoor");
        e=find_object(ACME_PAST+"area/edoor");
        w=find_object(ACME_PAST+"area/wdoor");
        s=find_object(ACME_PAST+"area/sdoor");
n->unlock_door("north");
e->unlock_door("east");
w->unlock_door("southwest");
s->unlock_door("southdown");
          this_object()->delete("Sky-City-War");
        }
return;
}

void init()
{ 
//     add_action("do_shout","shout")
}
int do_shout(string arg)
{
        int i,j;
        object me;
        me=this_player();
        if( !arg ) return notify_fail("你想要大叫什麼?\n");
        if( !wizardp(me) )
        {
                if( me->query("mp") < 15 )
                        return notify_fail("你的體力不夠, 沒有足夠的力氣喊叫。\n");
                me->add("mp",-15);
        }
      message_vision("$N想要在這裡大吼大叫，到是被縣老爺看破了。\n",me);
        if( me->query_temp("SKYCITY/shout") > 1 )
        {
                message_vision("縣老爺喝道："+me->query("name")+"！！你怎地如此頑固，氣死我了！\n",me);
                message_vision("縣老爺喝道：來人啊！！把"+me->query("name")+"押到大牢關了！！\n",me);
                message_vision("二旁走出四個官兵將$N押走了！\n",me);
                me->move(__DIR__"injail");
        }
        else {
                switch( random(2) ) {
                        case 0:
                        j=me->query_temp("SKYCITY/shout");
                        message_vision("縣老爺說道：咦！？$N膽敢咆哮公堂！？\n",me);
                        message_vision("縣老爺說道：來人啊！！把"+me->query("name")+"重重打十五大板！！\n",me);
                        message_vision("三位官兵走了過來，將$N強壓在地上，重重的打了十五大板！！\n",me);
                        me->receive_damage("hp",45);
                        me->set_temp("SKYCITY/shout",j+1);
                        break;

                        case 1:
                        i=me->query("wound/head");
                        j=me->query_temp("SKYCITY/shout");
                        message_vision("縣老爺說道：咦！？$N膽敢咆哮公堂！？\n",me);
                        message_vision("縣老爺說道：來人啊！！把"+me->query("name")+"重重的掌嘴十下。\n",me);
                        message_vision("三位官兵走了過來，將$N強壓在地上，重重的掌了十下的嘴。\n",me);
                        me->set_temp("SKYCITY/shout",j+1);
                        me->set("wound/head",i+10);
                        break;
                }
        }
        return 1;
}

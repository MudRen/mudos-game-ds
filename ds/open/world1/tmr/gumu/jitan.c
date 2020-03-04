// Room: /d/gumu/jitan.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void do_gain(object me, string name);

void create()
{
        set("short", HIC"石室"NOR);
        set("long",@long
一間空蕩蕩的石室，正前方放著一個祭壇，上面呈放著一些瓜果，
兩邊香燭散發出搖曳的火光，一些古墓弟子正將侵犯古墓的叛逆的首級
呈放(offer)在祭壇，兩側用來告慰先祖的英靈。
long);

        set("exits",([
                "west" : __DIR__"mudao21",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
      add_action("do_jibai","offer");
//      add_action("do_ketou","ketou"); 
}

int do_jibai(string arg)
{
        object ob, me=this_player();
        
        ob = present("head", me);
        if ( arg == "head")
        {
                if ( ! ob )
                            return notify_fail("你沒有人頭，無法祭拜。\n"); 
                  if(me->is_busy() ) return notify_fail("你正忙著，沒有空做祭拜。\n");

                if( ob->query("name") == "尹志平的首級"
                          || ob->query("name") == "洪凌波的首級"
                          || ob->query("name") == "李莫愁的首級" ) {
                        message_vision(CYN "$N恭恭敬敬地磕了幾個響頭，將$n呈放在祭壇上。\n" NOR,me,ob);
                        do_gain(me, ob->query("name"));
                        destruct(ob);
                         return 1;
                }
                return notify_fail("這顆人頭好象不是古墓的叛逆，會不會是你殺錯人了？\n");
        }
    return notify_fail("你想要拿什麼祭拜？\n");
}

void do_gain(object me, string name)
{
        string msg = HIR"\n【活死人墓】";
        if(name=="尹志平的首級")
                msg += HIY"全真教淫賊「尹志平」終於伏誅在"+ me->name(1)+"的手中，這個義舉在江湖上傳了開來。\n\n" NOR;
        else 
                msg += HIY""+ me->name(1)+"替古墓派除掉叛逆的義舉在江湖上傳了開來。\n\n" NOR;

        message("world:world1:vision",msg,users());
        tell_object(me, HIG"你得到一點聲望了。\n"NOR);
        me->add("popularity",1); //聲望
        me->start_busy(1);
}

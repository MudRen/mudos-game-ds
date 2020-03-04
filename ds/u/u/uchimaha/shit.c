#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"白便便"NOR,({"white shit","shit"}));
        set("long","這是一坨非常稀有的白色便便, 是烏漆嗎黑專用的坐騎。\n");
        set("race","野獸");
        set_weight(30000);

        set("limbs", ({"身體","胸部","腹部" }));
        set("verbs", ({ "bite","claw","crash" }));

        set("level",50);
        set("age",2);

        set_temp("apply/damage",10);
        set_temp("apply/armor", 15);
        set_skill("unarmed",100);
        set_skill("bagi_fist",100);
        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("windmove",50);
        map_skill("unarmed","bagi_fist");
        map_skill("dodge","windmove");
        
        set("no_get",1);
        set("no_drop",1);
        set("amount",1);
        set("ridable",1);

        set("chat_chance",1);
        set("chat_msg",({
  (: command("dog") :),
  (: command("cat") :),
  this_object()->name()+"在路旁學狗叫。\n",
  (: command("pure") :),
  (: command("jump") :),
  (: command(":D") :),
  (: command(":)") :),
  (: command(":P") :),
}));
        set("unit","坨");
        set("value",40000);
        set("member0","none");
        set("member1","none");
        set("member2","none");
        setup();
}

void init()
{
        add_action("do_member","member");
        add_action("do_run","run");
        add_action("do_name","name");
}

int ride_before_action(object me)
{
        object ob=this_object();
message_vision("$N用盡了力氣, 征服了"+this_object()->name()+"。\n",me);
        //me->set_temp("apply/short",({ me->short()+HIY"< 正騎著"NOR+this_object()->name()+HIW" >"NOR}));
        return 1;
}

int ride_after_action(object me)
{
        message_vision("$N穩穩的坐在"+this_object()->name()+"的身上了。\n",me);
        //this_object()->set_weight(10);
        //this_object()->move(me);
        return 1;
}

int ride_off_action(object me)
{
        message_vision("$N從"+this_object()->name()+"的背上摔了下來。\n",me);
        //me->delete_temp("apply/short");
        return 1;
}

int do_member(string arg)
{
        int n_save;
string where;
        object me;
        me=this_player();
        if( !arg || sscanf(arg,"here at %d",n_save)!=1 )
                return notify_fail("指令格式: member here at <第幾個記億>. \n");
        if( n_save > 3 || n_save < 1)
                return notify_fail("白便便恐怕沒你記得那麼多吧...。\n");
        n_save -= 1;
        where=(string)file_name(environment(me));
        message_vision("$N努力叫白便便把這裡的景色記起來。\n",me);
        set("member"+n_save, where+".c");
        return 1;
}

int do_run(string str)
{
        int n_save;
        string arg;
        object me=this_player();

        if( !me->query_temp("ride") )
                return notify_fail("你並沒有騎著馬。\n");
        if( me->query_temp("horse_run") )
        return notify_fail("你正在騎著馬往某地前進中喔。\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("指令格式: run at <馬的第幾個記憶>. \n");
        if( n_save > 3 || n_save < 1 )
                        return notify_fail("沒這個記憶喔....。\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("你好像沒有叫牠記住什麼，所以牠並沒有什麼反應。\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("你不就在這裡了？\n");
        tell_room(environment(me),me->name()+"騎著他的"+this_object()->name()+"飛上天去。\n",({ me }));
        me->move("open/world1/cominging/area/npc/obj/runwait");
        tell_object(me,"你開始往某地前進．．．\n");
        me->start_busy(10);
        me->set_temp("horse_run",1);
        call_out("for_go",3,me,this_object(),arg);
        call_out("for_go1",10,me,this_object(),arg);
        call_out("for_go2",13,me,this_object(),arg);
        return 1;
}

void for_go(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIY"$N騎著$n緩慢的往"+go_room->query("short")+"前進去．．．．．\n"NOR,me,ob);
        return;
}

void for_go1(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIC"慢慢的，$N已快到達了目的地了．．．．．．\n"NOR,me);
        return;
}

void for_go2(object me,object ob,string where)
{
        me->move(where);
        tell_object(me,HIR"你到達了目的地了！∼∼\n"NOR);
        tell_room(environment(me),me->name()+"突然從一個地方騎著他的"+ob->name()+"降落在你面前。\n",({ me }));
        ob->move(me);
        me->delete_temp("horse_run");
        return;
}
void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIW"\n  [小道消息]:"HIC"\n\n\t傳說中的可愛 "HIW"白便便"HIC"竟然被"+ob->name(1)+"狠心的沖到馬桶裡去了!!\n\n"+NOR,users());
        ::die();
        return;
}


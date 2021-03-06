#include <ansi.h>
#include <login.h>
inherit ITEM;

void create()
{
        set_name(HIR"光輪"HIC"２０００"NOR,({"super broom","broom"}));
        set("long","一把能飛來飛去的掃把•可以用member記住要飛去的地方•再用run飛到想去的地方•\n");
        set_weight(3000);

        set("no_get",1);
        set("amount",1);
        set("ridable",1);

        set("unit","把");
        set("value",1000);
        set("member0","none");
        set("member1","none");
        set("member2","none");
        setup();
}

void init()
{
          add_action("do_member","member");
          add_action("do_run","run");
}

int ride_before_action(object me)
{
        object ob=this_object();
        message_vision("$N向上一躍，接著就坐上了"+this_object()->name()+"的背上了。\n",me);
        return 1;
}

int ride_after_action(object me)
{
        message_vision("$N穩穩的坐在"+this_object()->name()+"的背上了。\n",me);
        return 1;
}

int ride_off_action(object me)
{
        message_vision("$N從"+this_object()->name()+"的背上跳了下來。\n",me);
        message_vision("$N忘了所有的記憶了！！\n",this_object());
        this_object()->set("member0","none");
        this_object()->set("member1","none");
        this_object()->set("member2","none");
        this_object()->set("member3","none");
        this_object()->set("member4","none"); 
        this_object()->set("member5","none");
        return 1;
}

int do_member(string arg)
{
        int n_save;
        string where;
        object me,env;
        me=this_player();
        if(! env = environment(me)) return 0;
        if( !arg || sscanf(arg,"here at %d",n_save)!=1 )
                return notify_fail("指令格式: member <第幾個記億>. \n");
        if( n_save > 5 || n_save < 1)
                return notify_fail("它恐怕沒你記得那麼多吧...。\n");
        if( !env->query("outdoors") )
                return notify_fail("它只能記得室外的景色。\n");
        if( env->query("no_horse_member") )
                return notify_fail("這這地點無法被它記憶。\n");
        n_save -= 1;
        where=(string)file_name(env);
        message_vision("$N努力叫$n把這裡的景色記起來。\n",me,this_object());
        set("member"+n_save, where+".c");
        return 1;
}

int do_run(string str)
{
        int n_save;
        string arg;
        object me=this_player();
        if(!me) return 0;
   if(me->query_temp("killer"))
  {
    write("你殺了人暫時不可以使用此令!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("你攻擊了玩家暫時不可以使用此指令!\n");
    return 1;
  }

    if( me->is_busy() || me->is_block() || me->is_fighting()) return notify_fail("你上一個動作還沒完成。\n");
        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你上一個動作還沒完成。\n");
        if( !me->query_temp("ride") )
                return notify_fail("你並沒有騎著它。\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("指令格式: run at <第幾個記憶>. \n");
        if( n_save > 5 || n_save < 1 )
                        return notify_fail("沒這個記憶喔....。\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("你好像沒有叫它記住什麼，所以牠並沒有什麼反應。\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("你不就在這裡了？\n");
        tell_room(environment(me),me->name()+"騎著他的"+this_object()->name()+"往別的方向而去。\n",({ me }));
        tell_object(me,"你騎著你的"HIR"光輪"HIC"２０００"NOR"，咻∼∼的一聲就到了目的地•\n");
        me->move(arg);        
        
        tell_room(environment(me),me->name()+"突然從一個地方騎著他的"+this_object()->name()+"來到了這裡。\n",({ me }));
        return 1;
}


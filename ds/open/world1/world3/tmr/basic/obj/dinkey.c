#include <ansi.h>
#include <path.h>
inherit ITEM;
int do_move(int i);

void create()
{
        set_name("舊世界電車",({"old world dinkey","dinkey"}) );
        set("long",@long
這是一台已為陣舊的小型電車，為舊世界殘留下來的機型，仍然採用
磁浮原理發動，連接舊世界礦區和主城的舊世界地下鐵路。雖然陣舊，但
仍然安全、快速，也是礦工能花費得起的運輪工具。
long
);
        set_weight(999999);
        if(clonep() )
                set_default_object(__FILE__);
        else {
                set("no_sac",1);
                set("no_get",1);
                set("value",9999);
        }       
        setup();
        call_out("do_move",60,1);
}

int do_move(int i)
{
        object temproom;
        temproom=find_object(__DIR__"dinkey_temproom");
        if(!environment(this_object() )) return 1;

        if(i==1)
        {
	tell_room(environment(),"嗶嗶嗶！！電車快速的關起車門，隨既發動開向主城。\n" );
          this_object()->move("/u/s/superbug/train/3");
        tell_room(environment(),"一台電車慢慢地停靠在月台邊.....\n");
        temproom->do_move(1);
        call_out("do_move",60,2);
        }
        else    {
	tell_room(environment(),"嗶嗶嗶！！電車快速的關起車門，隨既發動開向主城。\n" );
        this_object()->move(FUTURE+"tmr/basic/train_station1");
        tell_room(environment(),"一台電車慢慢地停靠在月台邊.....\n");
        temproom->do_move(2);
        call_out("do_move",60,1);
        }
        return 1;
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="dinkey")
                return 0;
        if(!me->query_temp("dinkey_ticket"))
        {
                tell_object(me,"你並沒有買車票，無法進去電車。\n");
                return 1;
        }

        me->move(__DIR__"dinkey_temproom");
        message_vision("$N從電車開啟的車門走了進來。\n",me);
        me->delete_temp("dinkey_ticket");
        return 1;
}


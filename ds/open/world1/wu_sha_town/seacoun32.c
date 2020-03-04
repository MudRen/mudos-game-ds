#include <path.h>
#include <ansi.h>
// #include <room.h>
// 沒用到 DOOR. by cominging
inherit ROOM;
void create()
{
        set("short","內堂");
        set("long",@LONG
這裡是林繁榮家的內堂, 你可以看見窗戶旁香案上擺
放著祭品和放在正中的媽祖像, 顯然林繁榮本人也是水手
出身, 你對於他的敬意更是油然而生... 你忽然發現香案
上似有一個錦盒閃閃發光.....?
LONG
    );
        set("exits",([ "south":__DIR__"seacoun31",
]));
        set("item_desc",([
        "香案" : "你發現香案上有一個金光閃閃的東西!\n",
        "錦盒" : "你發現錦盒裡裝了許\多金絲漁網...不知道有啥用?\n",
        "金絲漁網" : "你可以把它拿(take)起來.\n",
]));
        set("no_clean_up",0); 
        set("light",1);
        delete_temp("long");
        delete_temp("take_tackle");
        remove_call_out("create");
        setup();
} 

void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object me, p;
        object room = environment(this_player());
        me = this_player();
        if( arg != "金絲漁網" ) return 0;
        if(room->query_temp("take_tackle") == 0)
        {
                message_vision(HIC"$N從錦盒中將金絲漁網拿了出來。\n"NOR  ,me);
                p=new(PAST+"obj/gold_tackle.c");
                p->move(this_player());
                room->set_temp("take_tackle",1);
                room->set_temp("long", @LONG
這裡是林繁榮家的內堂, 你可以看見窗戶旁香案上擺
放著祭品和放在正中的媽祖像, 顯然林繁榮本人也是水手
出身, 你對於他的敬意更是油然而生...
LONG
                );
                delete("item_desc");
                call_out("create", 600);
        }
        else
        {
                tell_object(me,HIR"漁網早給人家拿走囉！\n"NOR);
        }
        return 1;
}


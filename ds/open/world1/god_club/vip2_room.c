#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"好一個房間"NOR);
        set("long", @long

這是一個充滿著神聖氣息的房間，站在這裡，你感覺到自己就像聖人
無數的情感湧上心頭，不禁讓你想吟個詩、作個對了。

long    );
        set("light", 1);
        set("exits", ([
  "southwestdown": __DIR__"flag_devilrom.c",
]));
set("outdoors","land");
        setup();
        set("stroom", 1); 
}
/*
int room_effect(object me)
{
        switch(random(5))
        {
         case 0:
         write("你站在窗前，享受著陽光沐浴的快感。\n");
         tell_object(me, HIY "你覺得全身都充滿了活力。\n" NOR ); 
me->delete("wound");
me->receive_heal("hp",200);
         return 1;

         case 1:
         write("你躺在床上，感受著風吹進房間的氣息。\n");
         tell_object(me, HIC "你覺得頭腦清醒了不少。\n" NOR ); 
me->delete("wound");
         me->receive_heal("mp",200);
         return 1;

         case 2:
write("你覺得無聊，於是在房間內練起了拳法。\n");
         tell_object(me, HIB "你覺得全身充滿精力，好不暢快！\n" NOR ); 
         me->receive_heal("ap",200);
me->delete("wound");
         return 1;
         default:       return 1;
         }
}

void init()
{
        add_action("do_full","full");
}
int do_full(string arg)
{
        object me;
        me = this_player();
        if( me->is_busy() )
                return notify_fail("你還在忙吧, 應該沒時間去吸氣. \n");
                me->start_busy(1);

call_out("full",0,1,me);
call_out("full",0,2,me);
        return 1;
}

void full(int c,object me)
{
        switch(c) {
        case 1:
                tell_object(me,HIC"你大大的吸了一口神聖之氣．．\n"NOR);
                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
                tell_object(me,HIG"你覺得精神飽滿，全身充滿力量！\n"NOR);
                me->set("hp",me->query("max_hp") );
                me->set("mp",me->query("max_mp") );
                me->set("ap",me->query("max_ap") );
                        break;
        }
}
*/

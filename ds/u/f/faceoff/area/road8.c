inherit ROOM;
static int on_journey = 0;
private void confirm_journey(string arg);

void create()
{
        set("short","小徑");
        set("long","你正從十萬大山往天城的路中。\n");
        set("distance",10);             //設定兩地的距離。
        set("to_room",__DIR__"road6");       //設定目的。
        set("from_room",__DIR__"ten_mountain1");     //設定起點。
        setup();
}

varargs int do_look(object me, string arg)
{
        if( on_journey==1 )
                write("你正從十萬大山往天城的旅程中，如果你想回頭﹐可以打 return。\n");
        else if( on_journey==-1 )
                write("你正往回走向原來出發的地方。\n");
        return 0;
}
void init()
{
        add_action("do_return", "return");
        add_action("do_look","look");
        call_out("confirm_journey",0);
}

private void confirm_journey(string arg)
{
                on_journey = 1;
                call_out("arrive_destination", query("distance"), this_player());
                this_player()->start_busy(query("distance")/2);
                do_look(this_player());
}

private void arrive_destination(object me)
{
        string res;

        if( !objectp(me) ) return;

        if( on_journey == 1 ) res = me->move(query("to_room"));
        else    res = me->move(query("from_room"));

        if( !res ) {            //沒有目的或是起點。
                this_player()->start_busy(query("distance") );
                call_out("arrive_destination", 10,me);
                return;
        }
        destruct(this_object());
}

private int do_return(string arg)
{
        if(on_journey==-1)
               return notify_fail("你已正在回途中了。\n");
        on_journey = -1;
        write("你開始往回走。\n");
        set("long","你正從十萬大山往天城回去的路上。\n");
        return 1;
}


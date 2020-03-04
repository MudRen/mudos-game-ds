inherit ROOM;
static int on_journey = 0;
private void confirm_journey(string arg);

void create()
{
        set("short","�p�|");
        set("long","�A���q�Q�U�j�s���ѫ��������C\n");
        set("distance",10);             //�]�w��a���Z���C
        set("to_room",__DIR__"road6");       //�]�w�ت��C
        set("from_room",__DIR__"ten_mountain1");     //�]�w�_�I�C
        setup();
}

varargs int do_look(object me, string arg)
{
        if( on_journey==1 )
                write("�A���q�Q�U�j�s���ѫ����ȵ{���A�p�G�A�Q�^�Y�M�i�H�� return�C\n");
        else if( on_journey==-1 )
                write("�A�����^���V��ӥX�o���a��C\n");
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

        if( !res ) {            //�S���ت��άO�_�I�C
                this_player()->start_busy(query("distance") );
                call_out("arrive_destination", 10,me);
                return;
        }
        destruct(this_object());
}

private int do_return(string arg)
{
        if(on_journey==-1)
               return notify_fail("�A�w���b�^�~���F�C\n");
        on_journey = -1;
        write("�A�}�l���^���C\n");
        set("long","�A���q�Q�U�j�s���ѫ��^�h�����W�C\n");
        return 1;
}


//  -By Tmr-

inherit ROOM;

static int on_journey = 0;
private void confirm_journey(string arg);

void create()
{
        set("short","");
        set("long","�A���bxx��xx �������C\n");

        set("distance",10);             //�]�w��a���Z���C
        set("to_room",__DIR__"");       //�]�w�ت��C
        set("from_room",__DIR__"");     //�]�w�_�I�C
        
        setup();
}

varargs int do_look(object me, string arg)
{
        if( on_journey==1 )
                write("�A���bxx ��xx ���ȵ{���A�p�G�A�Q�^�Y�M�i�H�� return�C\n");
        else if( on_journey==-1 )
                write("�A�����^���V��ӥX�o���a��C\n");
        return 0;
}

void init()
{
        add_action("do_return", "return");
        add_action("do_look","look");
        if( this_player() ) {
                if( userp(this_player()) ) {
                        write("�A�T�w�n���}�o�Ӱϰ�ܡS[y/n]");
                        input_to("confirm_journey");
                } else
                        confirm_journey("no");
        }
}

private void confirm_journey(string arg)
{
        if( arg[0]=='y' ) {
                on_journey = 1;
                call_out("arrive_destination", query("distance"), this_player());
                this_player()->start_busy(query("distance") );
                do_look(this_player());
        } else if( arg[0]=='n' ) {
                this_player()->move(query("from_room"));
                destruct(this_object());
        } else {
                write("�A�T�w�n���}�o�Ӱϰ�ܡS[y/n]");
                input_to("confirm_journey");
        }
}

private void arrive_destination(object me)
{
        string res;

        if( !objectp(me) ) return;

        if( on_journey == 1 ) res = me->move(query("to_room"));
        else    res = me->move(query("from_room"));

        if( !res ) {            //�S���ت��άO�_�I�C
                this_player()->start_busy(query("distance") );
                call_out("arrive_destination", 5, me);
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
        set("long","�A���bxx��xx �^�h�����W�C\n");
        return 1;
}


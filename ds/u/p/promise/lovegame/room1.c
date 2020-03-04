inherit ROOM;
 
void create()
{
        set("short", "迷霧");
        set("long", @LONG
你正走在一條小路，只見得四週盡是濃霧彌漫，伸手不見五指，往前
望去，隱隱約約只見勉強見到丈許小路.....
LONG
        );
        set("no_recall",1);
                setup();
}
void init()
{
        call_out("check_seal",0,this_player() );
}


int check_seal(object me)
{
        object obj;
        if(objectp(obj=present("seal",me) ) && obj->query("name")=="驅風符" )
        {
        tell_object(me,"忽然起了一陣疾風，把你四週的迷霧吹開了。\n");
        me->move(__DIR__"room");
        }
        return 1;

}


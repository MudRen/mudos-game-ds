inherit ROOM;
 
void create()
{
        set("short", "迷霧");
        set("long", @LONG
你正走在一條小路，只見得四週盡是濃霧彌漫，伸手不見五指，往前
望去，隱隱約約只見勉強見到丈許小路.....
LONG);
        set("no_recall",1);
        set("outdoors","forest");
        setup();
}
void init()
{
        call_out("check_seal",0,this_player() );
        add_action("do_go","go");
}

int do_go(string dir)
{
        object me;
        me=this_player(); 
        if( sizeof(this_object()->query("exits")) > 0 ) return 0;                    if(me->query_temp("en/fog") <= 5 && random(2) == 1)
        {
                me->add_temp("en/fog");
                me->move(__DIR__"en10"); 
                tell_room(environment(me), me->name()+"來到此地。\n", ({ me }));
        }
        else 
        {
                me->delete_temp("en/fog", 1);
                me->move(__DIR__"en7"); 
                tell_object(me,"經你一陣瞎走後，不知不覺中又回到了原點•\n");
                tell_room(environment(me), me->name()+"來到此地。\n", ({ me }));
        }            return 1;
}

int check_seal(object me)
{
        object obj;
        if(objectp(obj=present("seal",me) ) && obj->query("name")=="驅風符" 
           && random(2) == 1)
        {
        tell_object(me,"忽然起了一陣疾風，把你四週的迷霧吹開了。\n"); 
        add("exits", ([ "northwest" :  __DIR__"foxhole/forest/map_14_14.c"]));
        destruct(obj);
        } 
        return 1;

}


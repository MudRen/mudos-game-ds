inherit ROOM;
 
void create()
{
        set("short", "�g��");
        set("long", @LONG
�A�����b�@���p���A�u���o�|�g�ɬO�@�������A���⤣�������A���e
��h�A���������u���j�j����V�\�p��.....
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
                me->move(__DIR__"en8"); 
                tell_room(environment(me), me->name()+"�Ө즹�a�C\n", ({ me }));
        }
        else 
        {
                me->delete_temp("en/fog", 1);
                me->move(__DIR__"en7"); 
                tell_object(me,"�g�A�@�}�M����A������ı���S�^��F���I�E\n");
                tell_room(environment(me), me->name()+"�Ө즹�a�C\n", ({ me }));
        }            return 1;
}

int check_seal(object me)
{
        object obj;
        if(objectp(obj=present("seal",me) ) && obj->query("name")=="�X����" 
           && random(2) == 1)
        {
        tell_object(me,"���M�_�F�@�}�e���A��A�|�g���g���j�}�F�C\n"); 
        add("exits", ([ "northwest" :  __DIR__"foxhole/forest/map_14_14.c"]));
        destruct(obj);
        } 
        return 1;

}


inherit ROOM;
 
void create()
{
        set("short", "�g��");
        set("long", @LONG
�A�����b�@���p���A�u���o�|�g�ɬO�@�������A���⤣�������A���e
��h�A���������u���j�j����V�\�p��.....
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
        if(objectp(obj=present("seal",me) ) && obj->query("name")=="�X����" )
        {
        tell_object(me,"���M�_�F�@�}�e���A��A�|�g���g���j�}�F�C\n");
        me->move(__DIR__"room");
        }
        return 1;

}


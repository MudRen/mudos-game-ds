inherit ROOM;
void create()
{
set("short","��K");
set("long", @LONG
�A����o��, �o�{�|�P���O�G���F�ý��M��K, �o�̦��G�O�S���i�H
���F, ���A����ı�o�ۤv�O�g���F.
LONG
);
set("outdoors", "desert");
set("exits", ([ 
                "west"  : __DIR__"tree1.c",
                           ]));
 set("item_desc",([
        "��}":"�@�ӥi�H���H���i�h���p��}�C\n",
        ]) );
 
setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
       me=this_player();
        if (!arg || arg!="��}" ) return 0;
        message_vision("$N�w�b�a�W�ܧV�O���p�i��}�C\n",me);
        me->move(__DIR__"llll");
        tell_room(environment(me),me->query("name")+"���@�ӤH�q��}�~���F�L�ӡC\n",me);
        return 1;
}


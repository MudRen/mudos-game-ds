inherit ROOM;
void create()
{
set("short","�s��");
set("long", @LONG
�A�ש󨫥X�·t���a��, �A�ݤF�@�U�|�P, �o�{�A�����b�s���W, �A
�~�F�ѭ�診���q�D, ��ӬO�i�H�q��o��, �o�̩P������F������
���u��.
LONG
);
set("outdoors", "forest");
set("exits", ([ 
                "enter"  : __DIR__"tree4.c",
                           ]));
set("item_desc",([
        "�s�_":"�u���@�I�I���p�},�����D�i���i�H�p�L�h,���L�A�i�H�ո�(enter)�C\n",
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
        if (!arg || arg!="�s�_" ) return 0;
        message_vision("$N������Y�����@���Q�t�@��,�ܫj�j�~���i�h�C\n",me);
        me->move(__DIR__"lllll");
        tell_room(environment(me),me->query("name")+"�q�s�_�̪��F�X�ӡC\n",me);
        return 1;
}
        




// Room: /open/world1/tmr/bagi/rift1.c

inherit ROOM;

void create()
{
        set("short", "�s�_��");
        set("long", @LONG
�A�������b�@�s�_���A���l��ǰ�w�����ۨ�o�A�ݤߩM��I�����@
�h�A�譺��V���ɦ��}�D���z�L�s�_�j�V�F��C�s���W�@�������q��B��
�X�Ӫ��ý��A���H�����y�ۡC
LONG
        );
        set("world", "past");
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"glade",
                "east" : __DIR__"rift",
        ]));
        set("item_desc", ([ /* sizeof() == 2 */
        "�ý�" : "�@���ݨ��ٺ���T���ý��A�p�A���x�q���ܡA�����i�H�յ��k��(climb)�ոաC\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="�ý�" ) return 0;
          if(me->query("level") < 25) {
                message_vision("$N�ϺɤF�ۦ��A���M�������H���n�\\���ý��C\n",me);
                return 1;        
        }
        message_vision("$N�@�⮻���ý��A�Ⱖ��@�W�@�U���t�a�k���W�h�C\n",me);
           me->move(__DIR__"ghat1");
        tell_room(environment(me),me->query("name")+"�q�V�䱴�F���Y�A�H�Y���F�W�ӡC\n",me );
        return 1;
}



// Room: /open/world1/tmr/gumu/xiaoting.c

inherit ROOM;

void create()
{
        set("short", "�p�U");
        set("long", @LONG
�o���O�@�Ӥp�p���U��C�A����o���A�P�򪺥��u�G�F�@�ǡA�A�o
ı���W�U�I�ۤ@�Ǫo�O�C�U�������m���Ӥ�²���A�@��@�ȳ����B��
���������C�n�����@���۪�(door)�C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "door" : "�@���p�����۪��A���ȷȪ����S�����C�A�{�u�ݤF�ݡA�o�{���䪺�۾��W���G��������s(press button)�i�H�}���C
",
]));
        set("current_light", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mudao09e",
  "east" : __DIR__"mudao12",
]));

        setup();
}


void init()
{
        add_action("do_an", "press");
}

int do_an(string arg)
{
        object room, me = this_player();

        if( !arg || arg != "button" )
        {
                message_vision("�A�b�۾��W�ë��@��A���F�@��ǡAԣ�]�S�N�ۡC\n", me);
                return 1;
        }
        if( query("exits/south"))
        {
                return notify_fail("�۪��w�g�O�}�ۤF�C\n");
        }
        if( me->query_skill("unarmed", 1) > 10)
        {
                message_vision("$N���b�۪��e�A�]�����b�������F�@�U�A�۪��s�s�T�ۡA�w�w���}�F�C\n", me);
                if( !(room = find_object(__DIR__"mudao11")) )
                        room = load_object(__DIR__"mudao11");
                set("exits/south", __DIR__"mudao11");
                room->set("exits/north", __DIR__"xiaoting");
                tell_room(room,"�uť�o�۪��b�s�s�n���Q�w�w���}�C\n");
                remove_call_out("close");
                call_out("close", 5, me);
        }
        else
                message_vision("$N�յۦb�۾��W���ӫ��h�A�i�O�۪��������ʡA�u�o�}�F�C\n", me);
        return 1;
}

void close(object me)
{
        object room;

        tell_room(this_object(), "�۪��w�w�a���W�A��_�F�쪬�C\n");
        delete("exits/south");
        if( !(room = find_object(__DIR__"mudao11")) )
                room = load_object(__DIR__"mudao11");
        room->delete("exits/north");
        tell_room(room,"�_�𪺥۪��w�w�a���W�F�C\n");
}


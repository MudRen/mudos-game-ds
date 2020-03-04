// Room: /open/world1/tmr/freezetaoism/temple7.c

inherit ROOM;

void create()
{
        set("short", "�H���D�[-�I��");
        set("long", @LONG
�o�̬O�D�[�����@�y�I�ǡA���D�[�D���ɱ`�������I���ж��A�Ǥ���
�~�����ӻZ�Υ~�A�N�A�]�S����L�F��A�i���O²���췥�I�A���]�ݱo�X
�Ӧb���I�ɡA�i�H�j�j��֥~�ɪ��z�Z�C
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"temple4",
        ]));
        set("no_clean_up", 0);
        set("item_desc",([
        "�Z��":"�@�ӧ��_�ӫܵΪA���Z�ΡC\n",
        ]));

        setup();
}
void init()
{
        if( query_temp("have_down_road") ) {
                message_vision("�uť�o�@�}�ذճذժ��n�T�A���D�S���F�_�ӡC\n",this_player() );
                set("exits", ([ /* sizeof() == 1 */
                        "north" : __DIR__"temple4",
                ]));
		delete_temp("have_down_road");
        }
        add_action("do_move","move");
}
int do_move(string arg)
{
        if (arg != "�Z��")
                return 0;
        if( query_temp("have_down_road") ) return notify_fail("���D�w�g�}�ҤF�C\n");
        message_vision("$N�����F�Z�ΡA�{�X�@�����a�U�����D�C\n",this_player() );
                set("exits", ([ /* sizeof() == 1 */
                        "north" : __DIR__"temple4",
                        "down" : __DIR__"downroad1",
                ]));
        set_temp("have_down_road",1);
        return 1;
}


#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�Ϩk���g�c - "HIG"�B�L�Ѥ�"NOR);
        set("long", @LONG
�A�����b�@�ӥH���Y��򦨪��g�c�A���G�O�X�d�~�e�N�ئb�o�˪L��
���C��⪺�C�a�Ϊ�󪦺��F�|�g�@���S�@��������A�P�˪L�۵M�ӵM�a
�ĦX�b�@�_�C�A���M���B�b�g�c�����A���O�ˤ]����۷Q�n���}�C�b�A��
�e���q�ߤ@�ʤd�~����A�A���Y�W��A�u�@����F���W�J�ѡA���ݤ��쯫
�쪺���ݡC
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "�B�L�Ѥ�" : "�B�L�Ѥ찪�q�J�ѡA�A�`�N���ڳB���ӻ�j����}�C
",
  "�B�L��}" : "�B�L��}�̭��@�����¡A�A���I�Q�n�i�h(enter)�̭����I�C
",
]));
        set("no_clean_up", 0);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"maze5",
  "north" : __DIR__"maze11",
]));
        set("current_light", 3);

        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg) {
        if( arg != "�B�L��}" ) return notify_fail("�A�Q�n�i����̡H\n");
        if(this_player()->is_busy())
                return notify_fail("�A�����ۡC\n");
        message_vision("$N�@�s���N����}�̪��h�C\n", this_player() );
        this_player()->move(__DIR__"tree1");
        message_vision("$N�q��}���F�i�ӡC\n", this_player() );
        return 1;
}



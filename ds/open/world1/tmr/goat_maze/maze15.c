#include <ansi.h>
// Room: /open/world1/tmr/goat_maze/maze15.c

inherit ROOM;

void create()
{
        set("short", "�Ϩk���g�c - "HIM"�a������J�f"NOR);
        set("long", @LONG
�A�����b�@�ӥH���Y��򦨪��g�c�A���G�O�X�d�~�e�N�ئb�o�˪L��
���C��⪺�C�a�Ϊ�󪦺��F�|�g�@���S�@��������A�P�˪L�۵M�ӵM�a
�ĦX�b�@�_�C�A���M���B�b�g�c�����A���O�ˤ]����۷Q�n���}�C�b�A��
�e�O�@�y�a�����誺�J�f�A����e���۪����_���a���`�B�U�h�A�A���b�J
�f���U�ݡA�u�ݨ�º����@���A�`������ 
LONG
        );
        set("shrot", "�Ϩk���g�c - �����");
        set("no_clean_up", 0);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"maze11",
  "down" : __DIR__"stairway1",
]));
        set("current_light", 3);

        setup();
        replace_program(ROOM);
}


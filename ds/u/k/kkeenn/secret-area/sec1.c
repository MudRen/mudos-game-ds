#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "�a�U���j��");
        set("long", @LONG
�@�����R�����������z�O���q�l�W�b���e�ݥߪ��A�ݨӬO���i��j��
�q�L�F�A�b�q�l�W���W�豾�ۤ@�i�q�l�G�i( note )�A�b�������䦳�ۤ@
���ݯʪ��j�Ѫ��K�O�A�W���Q�H�ΰ������l�ƥX[ �a�U�q�|���ݫ��� ]�X
�Ӥj�r....
LONG
        );
        set("item_desc",([
     "note": "[31m�Ф��n�W�N�}�a��, �ڭ̥u�O�ȶ��F�J�I, �X�ȽЦۦ�}��[0m

",
        ]));
        set("exits", ([ /* sizeof() == 4 */ 
 "north":__DIR__"sec2.c",
]) );
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("no_clean_up", 0);

        setup();
 create_door("north","�q�Ϫ�","south",DOOR_OPENED,"nokey");
}



// Room: /u/a/alickyuen/area/dr19.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
���쨫�Y�����Y�A�A�o�{���@�D�D�`���[���Ъ��b�A���e�A�b�ݲM��
�I�A��ӳo�O�Y���f�Ъ��Ҧb�a�A�����H�a�~��������A�A�ݨ�o���f�g
�ۡG�u�����H���A�ФŨӶi�C�v
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dr18",
"east" : __DIR__"dr20",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "��" : "�o�O�@�D�|�۰ʶ}�����C\n",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="east" ) tell_object(me,"��A���Q���h�}�������ɡA����M�۰ʥ��}�F�A��ӬO�@���m�۰ʪ��n�C\n");
        return ::valid_leave(me, dir);
}
#include <path.h>

inherit ROOM;

void create()
{
        set("short", "����p��");
        set("long", @LONG
�@���u�ۤp�˪��D���A���y���A���ɥi�ݨ�ά�������b���Y����
�A�٦��Q�ӭӤp�Ĥl�b�˸��������A�A�D����Ǫ��Ъ٬ҬO�@�ǥΤ����
�y�����СA���F�_���h�N�O���O�u���_�˪L�v�F�C
LONG
        );
        set("world", "past");
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/sign" : 1,
]));
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
   "northeast":TMR_PAST"ghost-forest/forest1",
  "west" : __DIR__"street3",
    
]));
        set("no_clean_up", 0);

        setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
  ::valid_leave();
  if( dir=="northeast" && !userp(me))
  return notify_fail("���̥u�����a�~��i�h�C\n");
  return ::valid_leave(me, dir);
}


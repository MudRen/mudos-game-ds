inherit ROOM;

void create()
{
	set("short", "�u��");
	set("long", @LONG
�o�O�@���u�СA�b�o�̦��\�h���u�H�b�o�𮧡A�o�̬O�u�H�𮧥H
�ά����ƶ����a��A�a�W���ۤ@��諸�u�H�A�٦��@�ǨǪ��I�M�A�j��
�O��Χ���^��o�̥𮧡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path6",
]));
	set("no_clean_up", 0);
	set("item_desc",([
  "�I�M" : "�@��ݰ_�ӫܨI�����M�A���L�ƹ�W�o����򪺭��A�j���O���ǭ�]�a�C\n",
]));
	set("objects",([
  __DIR__"npc/worker.c" :2,
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}

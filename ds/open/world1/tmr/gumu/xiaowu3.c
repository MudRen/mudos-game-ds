// xiaowu3.c �]�C�C�p��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o���O�������U���@���p�ΡA���B�o�����@�Ф��V�C�\�]�N�p
���q�H�a�@��A���쪺��ȡA�ӺϪ��M���A�I�����j�ɡC�A²���Q�H��
��o�ղ`���j�Ӥ����٦��o���\�]�C
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao13",
	]));
	set("objects", ([
		__DIR__"obj/ping" : 1,
          __DIR__"npc/sun" : 1,
            __DIR__"npc/girl1" : 3,
	]));


	setup();
	replace_program(ROOM);
}

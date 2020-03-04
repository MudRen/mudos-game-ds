// Room: /u/t/truewind/Minetown/area/leaderroom.c

inherit ROOM;

void create()
{
	set("short", "�q�������ж�");
	set("long", @LONG
�o�̬O�������ж��A���Y�Ů�Q�����M�s�C�ж��������@�Ӥp��
��A�W�Y�\�ۤ@�[�����Ȫe���;��A�j�j�p�p���Ȫe�b�A���e�{�{�A
�Q�������R�C���観�@�y�ӱ�i�H�W�G�ӡA���G�O�q�������שЪ�
�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("objects", ([ 
        __DIR__"npc/leader.c" :1 ,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"minetown9",
  "up" : __DIR__"leaderroom1",
]));

	setup();
}

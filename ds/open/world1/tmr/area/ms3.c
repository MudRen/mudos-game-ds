// Room: /u/t/tmr/area/ms3.c

inherit ROOM;

void create()
{
	set("short", "�p����");
	set("long", @LONG
�A�����b�p����e�A���`���ʼƤH�X�ꪺ�j�_��A�𸭭Z���c�h�A��
���U���w�ۤ@���i�v�v���j�����A����̪�����]��۶������۬լպ��
�A�����W���е�]�O�O�@�n�A���M�����@���w�Ԫ��p�Ѧa�C
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "����" : "�R�ߩ�����W������A���o�X��ڪ������A�O�H�R������C
",
  "�j����" : "�@�����b�𽮩��U��ı���j�����A�������������w�����h�V�C
",
]));
	set("objects",([
	__DIR__"npc/frog" : 4 ,
	]) );
	set("outdoors","land");
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"ms2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

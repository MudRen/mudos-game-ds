// Room: /u/d/darkfool/area1/c2.c

inherit ROOM;

void create()
{
	set("short", "�s���F��");
	set("long", @LONG
�A���F���F�X�B�A�Ө�F�@�ڤj��W�e�A�A���⼾�N�������A�oı
��a�Q�����Ƽ�C�A�S���Y�ݤF�@�U�A��W�W�^�ۤ@���_�ۼ˪��F��A��
������@�ΡC�t�~�ȱo�`�N���a��O���X�ӹϧ�¶�۶�W��F�@��A�ӨC
�ӹϧΤU�����۶�L�Ϊ��W�ѡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"c1",
]));

	setup();
	replace_program(ROOM);
}

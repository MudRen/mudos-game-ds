// Room: /u/d/darkfool/area1/s3.c

inherit ROOM;

void create()
{
	set("short", "�n��v�ϵ�D");
	set("long", @LONG
�o�̬O��v�Ϫ��Y�Ө����A���䪺�p�άݨӤ����_���A������
���~���̩�۬ݨ����ӬO���q�Ϊ��u��b�i�i�X�X�C�n��]�����ޤH
�`�ت��Фl�A�¥ժ��~�[�A���M�]�O�t���Φ����G���ا󬰨嶮����
���C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shop2",
  "north" : __DIR__"s2",
  "south" : __DIR__"doctor",
]));

	setup();
	replace_program(ROOM);
}

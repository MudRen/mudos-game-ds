// Room: /u/d/darkfool/area1/17.c

inherit ROOM;

void create()
{
	set("short", "�_��v�ϵ�D");
	set("long", @LONG
�o�̥_�����@�l�j�Фl�A���OHANS�ҤU�q�~���q���ӭt�d���a�q
���ưȪ��t�d�H��ƳB�ݦ�a�A�ȥժ����f�B�L�W�F��j��HANS�лx
�A�ݨӻᦳ�z�O�C�A�b�Q�̭��������D�|���|�O�����񪺳å�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"16",
]));

	setup();
	replace_program(ROOM);
}

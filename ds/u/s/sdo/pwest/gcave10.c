inherit ROOM;

void create()
{
	set("short", "�}�]��");
	set("long", @LONG
�A���b�}�]�������A���U�|�g�A�o�{���ɫ�n�i�H��F�P����
���A�b�ݬݸ}���U�A���G�����y�L������A�A�o�~��M�j���A��ӳo
�̬O�Q�a�U�e�����[�ɶ��R��ҳy�������G�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gcave9",
  "east" : __DIR__"gcave12",
  "west" : __DIR__"gcave11",
  "south" : __DIR__"gcave13",
]));

	setup();
	replace_program(ROOM);
}

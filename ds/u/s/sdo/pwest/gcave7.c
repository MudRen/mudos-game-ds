inherit ROOM;

void create()
{
	set("short", "�}�]���q�D");
	set("long", @LONG
�A���b�o�̡A�o�{�a�ն}�l�V�U�ɱסA���O�۹諸�Ŷ��]�N�V��
�V�e�s�A�ӥB�̵}�i�Hť����y�n�A�ݨӳo���񦳦a�U�e�y�g�L�A��
�V���e�����y�n�V�ӶV�j�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"gcave6",
  "west" : __DIR__"gcave8",
]));

	setup();
	replace_program(ROOM);
}

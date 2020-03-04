// Room: /open/world1/tmr/advbonze/hill9.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�ѱ�");
	set("long", @LONG
�A�����b�ⶳ�p�W�ӡu�W�ѱ�v�W�A�A�i�H�ݨ쩵�۩��_�ӳq��
�s�����@�`�@�`�ѵM�۱�A�A��_�F�Y���s����F�L�h�A�{�b�~���F
�Q�X��Ӥw�A�ݼˤl�p�G�n��󪦤W�p�����ܡA�N�u���X�{�b���n�^
�h�s�}�F�C���L�A�A���G�Pı�o�쨫�o�y�W�ѱ�ɡA�ߤ��@�����ѵ�
�A���Pı�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill10",
  "southdown" : __DIR__"hill8",
]));
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}

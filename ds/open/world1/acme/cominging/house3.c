inherit ROOM;

void create()
{
	set("short", "�L��");
	set("long", @LONG
�@�����F�Ū����J�L����Ӷ}�P���ж��A�o�̦��X�ӧ��B��������
�L���|�Ѫ����աA�n���ä���򪺮e���q�L�A�L���|�Ѧ��G���y�v����
�l�A�b�Ǯ��ۮѡA�ݵۨ��s���B���յۡA�a�W�Q�ۤ@���a��A�W������
�U���U�˪��ϮסC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path4",
]));
	set("no_clean_up", 0);
	set("objects",([
  __DIR__"npc/m_soldier.c":1,
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}

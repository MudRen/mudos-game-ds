// yuzhengong.c �J�u�c
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�J�u�c");
        set("long", @LONG
�o�̬O�����c�H�e���§}�A�O���������u�H�Ѯ��j�D���e�M�ת�
�a��C��Ӥ�Х��u�Ы�A���a���G����b�Ӥp�A�N�N�����c�E��F
���s�W�A�N���a���s��W���J�u�c�A�H�����o�D���N�C�o�̫ܤ[�S��
�H�ӹL�F�A��ȤW���n���F�ǹСC
LONG
        );
        set("exits", ([
                "south" : __DIR__"fangzhenqiao",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 150);
	set("coor/z", 190);
	setup();
        replace_program(ROOM);
}
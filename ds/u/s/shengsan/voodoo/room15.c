
inherit ROOM;

void create()
{
	set("short", "�Ŭr�мp��");
	set("long", @LONG
�o�̬O�Ŭr�Ъ��p�СA����W�o�����o�������H�A�A�ݨ�@��ѧB�B
���b�i�������������A�Q���L�N�O�o�Ӽp�Ъ��p�v�F�A�����٦��X��L��
�{�̦b�����L������A�����p�I�ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south" : __DIR__"room14",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/cook" : 1,
	    __DIR__"mob/cookstudent": 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}

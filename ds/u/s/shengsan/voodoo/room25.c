
inherit ROOM;

void create()
{
	set("short", "�e�U");
	set("long", @LONG
���\�h���M�j�C�b���b�A�n�������𤧤W�A�C��L���ݰ_�ӳ��۷�
�W�Q�B����ˤO�C�Ӧb�A�_������W���F�@�T�j����(picture)�C
LONG
	);

	set("item_desc", (["picture":@NOTE
[1;32m
�o�T���ϥX�ۦW�a����A�W�������Ǧb�U�V����찪�a�W�b���A���
�D�Z�A�����t�x�C
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room24",
	    "west" : __DIR__"room26",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/believer" : 3,
	    __DIR__"mob/studentp" : 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}

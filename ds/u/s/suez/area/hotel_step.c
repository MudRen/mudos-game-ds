// Room: /u/s/suez/area/step1.c
inherit ROOM;
void create()
{
	set("short", "�ӱ�");
	set("long",@LONG 
�}�}���n�ѥ~�����p���ǤJ�A�X�M���@ŧ���u���b�A���}��A���A�X
�G�ˤ��o�V�W���h�C�p�G�O�b���Ԫ��]�ߡA�H�Ū�����N�o�˥R���۳o�@
�p���Ŷ��A���Hı�o�ܮ����Cť���ȴ̦���Q���ӷ|�ӳo�̡A�N�o�ˬݵ�
���~������A������ۤ����W���p���A��}�@�Y�Q���H�߭������C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "westdown" : __DIR__"hotel_path",
            "westup" : __DIR__"hotel_two",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
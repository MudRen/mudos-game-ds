inherit ROOM;

void create()
{
	set("short", "�g���˪L�J�f");
	set("long", @LONG
�A�o�{�o�̤w�g�S�����i�H���A�n�A���e���N�n�i�J�˪L������
�C�A�J�Ӫ����˪L���ݥh�A�ݨ��v�{�{�A�@�����٥H������ۧA
�]��L�ӡC�o�̴��ۤ@���i�ܵP�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"burg8",
                "enter" : __DIR__"wforest1",
	]));
	set("item_desc",([
        "�i�ܵP":"�z�w�w�w�w�w�w�w�w�w�w�{\n"
        	 "�x �� �g �� �� �L  �� �x\n"
        	 "�|�s�s�w�w�w�w�w�w�s�s�}\n"
        	 "  �x�x            �x�x  \n",
        ]));

	setup();
	replace_program(ROOM);
}

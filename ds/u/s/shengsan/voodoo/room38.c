
inherit ROOM;

void create()
{
	set("short", "�Ŭr�бо�");
	set("long", @LONG
�A�ݨ��Ǫ�����m���W���Y���C��A��W�����e���G�D���ۧŬr��
���биg�L�H�ζǩӪ����v�A�γ����[���]�Ʀ��W�h���X��ϧΡA�j�j�p�p
�H�Τ西��ʳ�����S��A�A�ݨ�Ю{�̽������F�Ϊ����ԤΪk���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room35",
	    "north": __DIR__"room39",
            ]));
	set("objects", ([ /* sizeof() == 1 */
	    __DIR__"mob/protector" : 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
���������D�A�O�H�Pı�F���A�D�W���ɦ��Ǳq�Τ�����n�ǥX�ӡA
�ٷ|���p�ߵ��Ať�F�i�h�A�o�̦��@�ڮڪ��٬W�A�S�ʤS�j�A�O�Τj�z
�۩M��^�۲V�X�������C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"house6",
  "west" : __DIR__"path3",
  "south" : __DIR__"path8",
]));
	set("item_desc",([
  "�d�W" : "�ʲʪ��d�W�A�W���٦����J��C\n",
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}

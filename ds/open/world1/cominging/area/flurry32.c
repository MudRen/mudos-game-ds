inherit ROOM;

void create()
{
	set("short", "�ӱ�");
	set("long", @LONG
�o�O�@�Ӥp�p���ӱ�A�A�����ݨ�n�観�@�Ӥj���A�e����������
�A�q���D���D���ݸg�L�o�@���A�ӳo�@�Ӽӱ�o�X�G�N�Ƥ��~���ܰ��b
�A�A��M�ݨ��X�ӶĤH�b�����~��M�j���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"flurry28.c",
  "northdown" : __DIR__"flurry34.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�̬O�����䪺�@�Ӥp�٥~�A�b�p�٪��~���ئ����餤����h��
�ᦷ�A�p�٬O�Ѧˤ�ҫئ��A�]�رo������F�ǡA�]���b���`�`���@��
�D���ʪ��X�{�A�p�٥~�٦��@�Ǥ��C
LONG
	);
	set("exits", ([
  "westdown" : __DIR__"flurry15.c",
  "east" : __DIR__"flurry21.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}

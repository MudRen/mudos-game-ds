inherit ROOM;

void create()
{
	set("short", "���D�汵�f");
	set("long", @LONG
�o�̬O���D�����ۥ汵�f�A���Y�W���ǤH���Ө��h�A����Τl�̤]
�}�}���o�X�@�ǲ��ʪF�誺�n���A�O�H�Pı���ǧn�A�F��N�O���Y���Q
�r�f�A�]�O�����ө����g�����C
LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry26.c",
  "east" : __DIR__"flurry28.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}

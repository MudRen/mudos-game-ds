inherit ROOM;
void create()
{
	set("short", "�^�����Φa�U");
	set("long",@LONG
�I���@�n�A�A�������^���b���a�A�A�[��F�@�U�|�P�A���\�\�h�h
���Z�\�K�ަb���A���L�o�]���ʦb�K�d�l���A�]�W�F��A�ҥH�A�S��k
�\Ū�A�b�F�誺����W�d���@�ǨǪ��r(word)�C
LONG
	);
	set("exits", ([
  "up" : __DIR__"herohouse1.c",
]));
	set("item_desc",([
  "word" : "����W�����r�]�������F���a�ӵL�k�ݲM�C\n",
]));
	set("no_clean_up", 0);
	set("light", 1);
	setup();
	replace_program(ROOM);
}
inherit ROOM;

void create()
{
	set("short", "�g���˪L���|");
	set("long", @LONG
���즹�B�A�A���I�Pı�쬰����n�s���y�g���˪L�z�F�C�]���b
�o�̪�������A�Pı��@�ة_�����Pı�A�n���L�̳��O�|�ʪ��A�ӥB
�~���{�U���ݵۧA�C�o�̦��������w���j���Y�A�����O�ѵM���A��
�_�ӹ��O���H�S�N�⥦�h�L�ӡA�ӥB�W���٦��@�Ǥ�r�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"east" : __DIR__"burg9",
  		"south" : __DIR__"burg7",
	]));
	set("item_desc",([
        "��r":	"�W���g�ۡy�ɸO�z����ӻȦ�r�񪺤j�r�A���U�٦��X��Ȧ�p�r�G\n\n"
        	"	�b�ѯ������Ҥ��U�A�վB���P�����שw��\n"
        	"	�󦹡A���H�g���˪L����ҡA�����I�ǡC\n"
        ]));

	setup();
	replace_program(ROOM);
}

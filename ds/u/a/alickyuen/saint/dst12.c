// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IEast[2;37;0m");
	set("long", @LONG
�H�s�b�o�̥����k��A�A�t�@�I�N�Q�����X�h�C��ӳo�̥_��������
�N�O���W���J�|���A�C�ѳ����@�s�H�ӳo�̶R�L�̪��J�|�A�ӥB�o�̪���
��O�@�Ӿ���ʪ���A�ҥH�o�J�|�����ȤH�U�ӷU�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dst11.c",
  "north" : __DIR__"cakeshop",
  "east" : __DIR__"dst13.c",
]));
set("objects",([
__DIR__"npc/soser" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IWest[2;37;0m");
	set("long", @LONG
�n���o�X�F�˧n���n���A�N���D�O�@�������b�s�y�Z���ɵo�X�����T
�C�ӭ������M�b�|�B�ƴ��A�ϱo�A�n���C���Q�ƹL�h���~��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"gate4.c",
  "south" : __DIR__"shop2.c",
  "east" : __DIR__"dst15.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

// Room: /u/a/acme/area/popshop.c

inherit ROOM;

void create()
{
	set("short", "�����E��");
     set("light",1);
	set("long", @LONG
�o�̬O�@����Q�A�A�i�H�ݨ�b���f���ⰼ�A�g�ۡy��������A��
��L�ۡz�K�Ӫ����j�r�A���K���d�i�e��F�ӯª�����L�A�u���x�d��
���Ӥߪ���۱b�U�A�L���S�ۯ��ۡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wynd",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/duan" : 1,
]));
       set("room_type","shop");        //��Q.���D����(�R��ҥi)
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// updated by alickyuen 27/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�IWest[2;37;0m");
	set("long", @LONG
ť��@�ǹ��s�i�q���q���A�N���Y�@�ݡA�o�{�ѪŤW�@�ӭӼs�i���B
��y�A�b�j�O�ŶǡC�A����@�i�ǳ�A�N�O���o�̷s�}�@��������A�ӥB
�s�i�������S���A�A�N�Q�֨Ƕ]�쨺�̬ݬݡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dst16.c",
//  "northdown" : "/u/s/steps/area/door",  �Ȥ��}
  "east" : __DIR__"dst14.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

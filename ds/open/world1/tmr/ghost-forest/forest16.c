// Room: /tmr/garea/forest16.c

#include <ansi.h>
#include <path.h>

inherit ROOM;

void create()
{
	set("short", "�����p��");
	set("long", @LONG
�A���b�@�B�L�����@���������W�A�b�F�n��V������d�ڸ��A����n
��V�b�L�줤����������o�{�����p���C���_�訫��X�˪L��F�ѫ��F��
�B�A�N�ȩ��M�_���A���i�N�����o���h�ѫ��F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southwest" : __DIR__"forest14",
	  "southeast" : __DIR__"forest15",
	  "north":__DIR__"road2",
 	]));
	set("outdoors", "forest");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	object ob;
	ob=this_player();
	if ( !ob->query_temp("kneel_ghost") )
	{
		tell_object(ob,HIW"���_����V���M�_�F�@�}����.......\n" NOR);
		set("exits", ([ /* sizeof() == 2 */
		  "southwest" : __DIR__"forest14",
		  "southeast" : __DIR__"forest15",
		  "north":__DIR__"road2",
	 	]));

	}
	else
	{
          set("exits", ([ /* sizeof() == 2 */
		  "southwest" : __DIR__"forest14",
		  "southeast" : __DIR__"forest15",
	          "north":ACME_PAST"area/forest1",
          ]));
	ob->delete_temp("kneel_ghost");

	}
}




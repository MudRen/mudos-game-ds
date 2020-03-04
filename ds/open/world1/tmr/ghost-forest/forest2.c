#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�L�������p��");  
	set("long", @LONG
�u���p���󦹩��F�_�B��_�G��V�A���F�G���Ӧ�A�u���G��ɬO�L
��A���F�����A�O�L���Ф����A�ө��_�������G���p���]�L�S�����B
�A�p�n�_��A�ꤣ���n�����@�Ӥ�V�樫�~�n�C
LONG	
	);

	set("exits", ([ /* sizeof() == 3 */
	  "northeast" : __DIR__"forest3",
	  "south" : __DIR__"road1",
	  "northwest" : __DIR__"forest4",
	]));

        set("outdoors","forest");
    	set("no_clean_up", 0);
	setup();
}

void init()
{
	object ob;
	ob=this_player();

	if(!ob->query_temp("kneel_ghost") )
	{
		tell_object(ob,HIW"���n����V���M�_�F�@�}����.......\n" NOR);
		set("exits", ([ /* sizeof() == 3 */
		  "northeast" : __DIR__"forest3",
		  "south" : __DIR__"road1",
		  "northwest" : __DIR__"forest4",
		]));
	}
	else
	{
  		ob->delete_temp("kneel_ghost");
		set("exits", ([ /* sizeof() == 3 */
		  "northeast" : __DIR__"forest3",
		  "south" : __DIR__"forest1",
		  "northwest" : __DIR__"forest4",
		]));

	}

}

/*	room.c					*
 *	write by alickyuen@ds 20-9-2001		*
 *	�޲z����`�����ϩж��s���{��		*/

#include <ansi.h>

void show_exit(object room)
{
	string file_name;
	
	file_name = replace_string(file_name(room), __DIR__, "");

	switch(file_name)
	{
		case "rm1":
			room->set("exits", ([
				"east" : __DIR__"en3",
				"west" : __DIR__"rm2",
				"north" : __DIR__"rm4",
				"south" : __DIR__"rm7",
			]));
			return;
		break;
		case "rm2":
			room->set("exits", ([
				"east" : __DIR__"rm1",
				"west" : __DIR__"rm3",
				"north" : __DIR__"rm5",
				"south" : __DIR__"rm8",
			]));
			return;
		break;
		case "rm3":
			room->set("exits", ([
				"east" : __DIR__"rm2",
				"north" : __DIR__"rm6",
				"south" : __DIR__"rm9",
			]));
			return;
		break;
		case "rm4":
			room->set("exits", ([
				"west" : __DIR__"rm5",
				"south" : __DIR__"rm1",
			]));
			return;
		break;
		case "rm5":
			room->set("exits", ([
				"east" : __DIR__"rm4",
				"west" : __DIR__"rm6",
				"south" : __DIR__"rm2",
			]));
			return;
		break;
		case "rm6":
			room->set("exits", ([
				"east" : __DIR__"rm5",
				"south" : __DIR__"rm3",
			]));
			return;
		break;
		case "rm7":
			room->set("exits", ([
				"west" : __DIR__"rm8",
				"north" : __DIR__"rm1",
			]));
			return;
		break;
		case "rm8":
			room->set("exits", ([
				"east" : __DIR__"rm7",
				"north" : __DIR__"rm2",
				"west" : __DIR__"rm9",
			]));
			return;
		break;
		case "rm9":
			room->set("exits", ([
				"east" : __DIR__"rm8",
				"north" : __DIR__"rm3",
			]));
			return;
		break;

		default:
			room->set("exits", ([
				"east" : __DIR__"en3",
			]));
			return;
		break;
	}


	return;
}


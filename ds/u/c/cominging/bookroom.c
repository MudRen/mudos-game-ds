#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", " == JohnnyS �ѩ� == ");
	set("long", @LONG

�o�̴N�O�@���ѩ�, �\�]���Z, �S����S�O, ��W���X�i�ȱ�, �]�\
�i�H(w_note)�Ӵ����ۤv�ƶ�, ���䦳�ӳ��Ȭ[���

LONG
	);
//        set("exits", ([  "west" : __DIR__"walkway.c"  ]));
	set("objects", ([
  __DIR__"item/paper_shelf.c": 1
]));
	set("outdoors", "forest");
	set("light", 1);
	set("no_clean_up", 0);
	setup();
        call_other("/obj/board/lpc_b.c", "???");
}

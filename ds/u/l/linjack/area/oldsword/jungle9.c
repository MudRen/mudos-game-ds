#include <room.h>
inherit ROOM;
void create()
{
 set("short","沼澤中");
 set("long",@LONG
你憑著你的腳底功夫勉強的走到了沼澤的中央, 水已經越來越
深了, 而且這沼澤裡不知道有什麼危險, 你最好是先離開比較安全,
要不然到時後若蹦出個妖魔鬼怪你就得呼天搶地了.....
LONG
    );
 set("exits",([ "west":__DIR__"jungle10",
		"south":__DIR__"jungle8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "糜爛酒把");
	set("long", @LONG
這裡是一間破舊的酒吧，吧台只有一個老舊的機器人在服務著，整間
店也只有稀稀疏疏的幾個酒客在喝酒，舞台上有著一群機器樂隊正在演奏
著，也許你可以點幾首歌來聽（ｌｉｓｔ）。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-3.c",
]));
set("objects", ([
__DIR__"npc/singer" : 1,
]));
set("item_desc", ([
"list" : "一張歌曲名單，你可以看看(read)有什麼你喜歡的歌。\n"
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}
void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
if(arg !="list" ) return 0;
tell_object(me, 
HIW"　　　歌曲名單\n\n"NOR
HIW"　１．只有我最搖擺 \n"NOR 
HIW"　２．call me\n"NOR
HIW"　３．愛一個人好難\n"NOR
HIW"　４．I can't cry\n"NOR
HIW"　５．如果雲知道\n"NOR
HIW"　６．月亮代表我的心\n"NOR
HIW"　７．雨一直下\n"NOR
HIW"　８．走在雨中\n"NOR
HIW"　９．不可能錯過你\n"NOR
HIW"１０．有染\n"NOR
HIW"１１．你是對的\n"NOR
HIW"１２．我不是一個愛過就算的人\n"NOR
HIW"１３．我可以抱你嗎？\n"NOR
HIW"１４．把你藏起來\n"NOR
HIW"１５．孟婆湯\n"NOR
);
        return 1;

}
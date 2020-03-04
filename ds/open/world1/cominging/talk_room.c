#include <ansi.h>
#include <path.h>
inherit ROOM;

string welcome = 
HIR"\n　　　　　┌────────────┐\n"
"　　　　　│　　　　　　　　　　　　│\n"
"　　　　　│　　歡迎來到聊天室∼！　│\n"
"　　　　　│　　　　　　　　　　　　│\n"
"　　　　　└────────────┘\n\n"NOR;

void create()
{
        set("short", HIC"聊"HIY"天"HIG"專"HIM"用"HIR"室"HIW);
        set("long",
HIW"\n 這裡是 "HIC"夢幻七域"HIW" 裡面 "YEL"Omaga"HIW" 剛新開的 "HIY"Chat"HIW" 專用 "HIY"Room"HIW"，如果想\n"
" 要"HIG"聊天"HIW"，或者是你只想要聊天，而不想要被人吵的話，就可以呆在這裡\n"
" 嚕！\n\n"NOR
        );
        set("exits", ([
  "out" : TMR_PAST"area/inn_2f.c",
]));
//      set("outdoors", "universe");
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_cast", 1);
        set("no_exert", 1);
        set("no_recall", 1);
        set("light", 1);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        tell_object(this_player(), welcome);
}

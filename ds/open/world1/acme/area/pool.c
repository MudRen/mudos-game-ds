// Room: /u/a/acme/area/pool.c
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "天池");
	set("long", @LONG
這裡就是天山有名的天池了，四周充滿了霧氣，天池的形成是因天池
上方的瀑布沖蝕而成，瀑布上有顆大石，因大石在此所以瀑布一分為二，
遠遠望去倒似是蛟龍之腳，大石上卻已長滿了綠色的青苔。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"pass1",
"northup" : "/open/world1/faceoff/sky/ten1",
]));
        set("hide_exits", ([ /* sizeof() == 1 */
                 //"north" : SKY_CLUB+"room55.c",
                 "north" : "/open/world1/manto/sky2_1f/map_7_13.c",
        ]));
	set("no_clean_up", 0);
    set("outdoors","land");
     set("item_desc", ([
"大石" : "這是瀑布上的大石，上面長滿了青苔，若自認輕功\不錯，或許\能跳(jump)上去。\n"
     ]));

	setup();
}
void init()
{
        add_action("typejump","jump");
}
     int typejump(string arg)
{
        object me;
        me=this_player();
        if(arg != "大石") 
         return 0;
        else {
        message_vision(
        "$N展開了不凡的輕功\，往大石上跳去。\n\n" ,me);
        me->move(__DIR__"rock");
        return 1;
             }
}

int valid_leave(object me, string dir)
{
       object obj;
        if( dir=="north" && !wizardp(me))
        {
        // 有不是天地的人能進去, hmm 暫時先增加個判斷. by -Acme-
        if(objectp(obj!=present("ring of heaven and earth",me)))
                return notify_fail("你身上沒有天地會的信物，無法進入。\n");
        	if( CLUB_D->check_member("sky",getuid(me))<1 ) return notify_fail("那裡只有天地會成員才能進去。\n");
        	if( me->query_temp("killer") )
        	{
        		message_vision(HIW"\n天上傳來一個幽幽的聲音: $N, 因為你剛剛殺了人所以暫時不能進入幫會。\n"NOR,me);
        		return notify_fail("你必須等通緝時間過了之後才能進入幫會。\n");
        	}
		if( me->query_temp("invader") )
		{
        message_vision(HIW"\n天上傳來一個幽幽的聲音: $N, 因為你剛剛傷了人所以暫時不能進入幫會。\n"NOR,me);
			return notify_fail("你必須等通緝時間過了之後才能進入幫會。\n");
		}
        }
        return ::valid_leave(me, dir);
}

inherit ROOM;

void create()
{
   set("short","小麥草大廳");
   set("long", @LONG
這裡是小麥草大廳,四周一塵不染,令人心礦神怡,這裡常有小麥草的
朋友來找他聊天打屁,總是聊的很開心..這裡放著一個留言板,先留
個言灌灌水在走吧。
LONG );
  set("light", 1);
  set("exits", ([/* sizeof() == 2 */
  
"west" : "/u/s/sexking/workroom/horseroom.c",
"east" : "/u/s/sexking/workroom/workroom1.c",
"north" : "/u/s/sexking/workroom/skillroom.c",
]));
set("objects", ([ /* sizeof() == 1 */
]));
set("no_clean_up", 0);
    set("no_kill",1);
set("valid_startroom", 1);
setup();
call_other( "/obj/board/sexking_b.c", "???" );
}


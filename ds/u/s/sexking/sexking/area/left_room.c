inherit ROOM;
void create()
{
        set("short", "左左小次郎帳蓬內");
     set("light",1);
        set("long", @LONG
你非常不尊敬的進入了扶桑強者-左左小次郎的帳蓬裡，
左左小次郎是一位劍術超強的高手，如果沒什麼事你應
該速速離開。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_18",
 ]));
set("objects",([
       __DIR__"npc/left" : 1,
    ]) );
   set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}

 

inherit ROOM;
void create ()
{
        set ("short",  "黑瞳的睡房" );
        set ("long", @LONG
這裡是黑瞳的睡房，從這裡你可以感到聖域傳來的神秘力量，
這種力量使你覺得不再疲勞，從窗外看出去，你可以看到玩家們正
努力挑戰聖鬥士中．這裡有一個流言版供各位提供意見．
LONG);
        set("light", 1);
        set("exits", ([ /* sizeof() == 4 */
   "luky":"/u/l/luky/workroom.c",
   "shengsan":"/u/s/shengsan/workroom.c",
   "wiz" : "/d/wiz/hall1",
   "east" : "/u/b/bennyng/test/rm1.c",
]));
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
         call_other( "/obj/board/bennyng_b", "???" ); 
}

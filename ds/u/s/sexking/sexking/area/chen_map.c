inherit ROOM;
void create()
{
        set("short", "小成深介帳蓬");
     set("light",1);
        set("long", @LONG
這裡是日本商人小成深介所住的帳蓬，周圍擺了些雜貨，你可以
向小成深介添購。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"map_6",
 ]));
set("objects",([
       __DIR__"npc/chen" : 1,
    ]) );
 
   set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}

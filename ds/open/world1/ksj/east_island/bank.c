inherit ROOM;

void create()
{
  set("short", "小錢莊");
  set("light",1);
  set("long", @LONG
這裡是一間小小錢莊，提供來往旅人提領金錢的服務。
LONG);
  set("exits", ([ /* sizeof() == 1 */
      "west" : __DIR__"room15",
     ]));
  set("objects",([
      __DIR__"npc/bank-keeper" : 1,
     ]) );
  set("room_type","bank"); 
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

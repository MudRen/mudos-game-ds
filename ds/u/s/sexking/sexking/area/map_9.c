inherit ROOM;

void create()
{
        set("short", "扶桑浪人營");
     set("light",1);
        set("long", @LONG
這裡就是遠近馳名的扶桑浪人營了，你的身旁有許多浪人武士們正在
聊天，也有的在練劍，看樣子個個都武術高強，但每個人都笑容可鞠，
畢竟也都是練武之人，他們應該都會很尊敬你。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"map_7",
  "north" : __DIR__"map_10",
  "east" : __DIR__"map_11",
  "west" : __DIR__"bath_1",
]) );
       set("outdoors","land");
       set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

inherit ROOM;
void create()
{
        set("short", "稻田");
     set("light",1);
        set("long", @LONG
這裡是扶桑浪人營的田園，十分遼闊，你看到壯丁們正在努力耕田，
旁邊還有幾個小孩子，似乎很很想變強，一直拿著木刀打向稻草人，
十分的有趣。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"map_5",
  ]));
 set("objects",([
       __DIR__"npc/japen_child" : 2,
       __DIR__"npc/scare" : 3,
    ]) );

   set("outdoors","land");
 set("no_clean_up", 0);
 setup();
        }

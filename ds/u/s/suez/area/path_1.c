
inherit ROOM;

void create()
{
 set("short","山中小徑");
        set("long",@LONG
落葉在你腳下沙沙的響，你正走在一條幽靜小路上。
LONG
        );

         set("exits", ([
         "southdown": __DIR__"hotel_f",
         "northeast": __DIR__"path_2",
         ]));
        
        set("outdoors","land");
        
        setup();
        replace_program(ROOM);

 }
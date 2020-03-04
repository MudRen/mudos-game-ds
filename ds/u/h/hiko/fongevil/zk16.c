inherit ROOM;
void create()
{
        set("short","山間野林");
        set("long",@LONG
山林不知名的禽鳥鳴叫，聲音盛為淒厲，令人神經突然繃緊，感覺好
像會有不祥的事發生，林中地面濕濘不堪，走來甚為不順，西北有一條山
道，東南則是陰暗的山林。
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"zk15",
  "southeast" : __DIR__"zk17",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



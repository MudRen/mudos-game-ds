inherit ROOM;
void create()
{
        set("short", "泊浪村市集");        
set("long",@LONG
這裡是市集中央，可以聽到一些鏘鏘的聲音，令人覺得怪怪，原來
是南邊有一家打鐵舖，裡面的打鐵師傅聽說和滄縣老師傅是同門，因此
打鐵技術也十分聞名，北邊是一家當舖，看得出來也是老字號了，東邊
則也是市集。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po8n",
  "west" : __DIR__"po7" , 
  "east" : __DIR__"po9",
  "south" : __DIR__"po8s",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}






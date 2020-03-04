
inherit ROOM;

void create()
{
       set("short", "正殿");
        set("long", @LONG
正殿內供奉著如來佛像，四五人高，莊嚴肅穆，身前一尊香爐，上插
三根半柱燃香，殿內飄著淡淡的檀香。一張壇木矮几擺放於佛像前，几上
烹茶之具齊備，清香之氣從青釉茶盞中飄起，絲絲縷縷，綿綿不絕。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"temple05",
  "south" : __DIR__"temple03",
]));
        set("no_clean_up", 0);
    set("objects", ([
    __DIR__"npc/bonze" : 1,
     ]) );
        set("light",1);
        setup();
        replace_program(ROOM);
}

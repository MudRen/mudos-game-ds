inherit ROOM;
void create()
{
        set("short", "泊浪村港口");        
        set("long",@LONG
你看到一群漁夫在努力工作，看來這裡已經是港口了，到處是一些
漁網和一些工具，地上也有一些劣質的魚被丟棄在地上，可以聞到濃厚
的魚腥味，北邊是泊浪村的港口，西邊則是漁會，漁會是屬於一種漁夫
們團結的團體，可以一起打擊外敵和解決事務。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po6",
  "south" : __DIR__"po4",
  "west"  : __DIR__"po5w",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




inherit ROOM;

void create()
{
       set("short", "寺前");
        set("long", @LONG
一座大殿，左右各一間仿殿，東西廂房是禪房與修持之所，可謂簡之
又簡，以至於損。而寺院前栽修竹，後植青松，山泉來自巨岩，繞寺而下
。天空澄明。群林郁郁蔥蔥，水清潭明，令你心隨之一暢，頗有吞吐天地
之感。
LONG
        );
        set("exits", ([ 
 "north" : __DIR__"temple03",
  "south" : __DIR__"temple01",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}

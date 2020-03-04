inherit ROOM;

void create()
{
       set("short", "西廂房");
        set("long", @LONG
這是普渡寺的西廂房，專門提供給進香在寺裡過夜。房內的擺設十
分簡單，只有一張竹床跟桌椅，生活十分簡樸。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"temple03",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}


inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"桃花洞"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    桃花洞是個土洞，位於玉笥山麓。洞穴裡面涼爽宜人，相傳從前屈
原在盛夏酷暑之時，常來此洞讀書養性，賦詩明志。

LONG
        );
    set("exits",([
 "west" : __DIR__"room09",
 "enter" : __DIR__"room11",
]));


        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}

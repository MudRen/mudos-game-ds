
inherit ROOM;

void create()
{
 set("short","小木屋");
        set("long",@LONG
一間老舊的小木屋，屋頂只剩下一半，牆壁也搖搖欲墜，到處都有著
巨大的爪痕，爪痕之中似乎還有些劍刺出來的痕跡。血跡及木屑四處散落
，由種種跡象看來，爪痕的主人大概已經不在世上了！
LONG
        );
        set("exits", ([
         "out":"/open/world1/tmr/ghost-forest/forest9",
                  ]));
        set("objects",([
              __DIR__"npc/yen-eu" : 1,
              ]) );
                
        setup();

        replace_program(ROOM);

 }

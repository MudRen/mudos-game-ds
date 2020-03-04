inherit ROOM;
void create()
{
        set("short", "山崗");
        set("long",@LONG
這裡看起來十分陰森，由山崗上看去可以看到許多的野墳，給人很
不想多留在此地，並且隱隱有一種寒冷的感覺，似乎就是所謂的陰脈，
平常也是渺無人蹤，而且越往前感覺就越強烈，附近的草葉隨風發出的
聲音也讓你渾身戰慄，西北和東北有兩條分叉小路。
LONG
        );
  
set("exits", ([
  "south" : __DIR__"zk22",
  "northwest" : __DIR__"zk10",
  "northeast" : __DIR__"zk11",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





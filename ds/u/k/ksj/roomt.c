inherit ROOM;
void create()
{
 set("short","ksj ���񪪳��");

 set("long",@LONG
    �@���C�񪺤j���A�A�X��i�ʪ��C
LONG
    );
 set("exits",([ 
 
    "north": __DIR__"room4", 
    "east": __DIR__"room8",
    ]));
 set("light",1);
 set("no_drop",1);
 set("no_get",1);
// set("light",1);
// set("light",1);
 setup();
}

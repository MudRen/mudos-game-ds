inherit ROOM;
void create()
{

set("short","村長家");
set("long", @LONG
這就是神木村村長的住處了, 屋內擺設非常漂亮, 兩旁皆擺滿了珍貴
的古董, 你深怕一不小心打破了這些古董, 因此你特別小心翼翼.
LONG
);
set("exits", ([                
"south" : __DIR__"rr_1.c", 

        ]));

 setup();
}


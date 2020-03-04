#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
從這邊往你前方的路望去, 可以看到一絲絲的光線, 但是這
光線仍然十分的昏暗, 可能只是蠟燭或是一大團螢火蟲在那邊而
已. 你雖然一直聽得到野獸的叫聲, 但你的直覺告訴你牠不在你
走的這條路上, 因為那個聲音太遙遠了.
LONG
    );
 set("exits",([ "west":__DIR__"jungle8",
		"south":__DIR__"jungle6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
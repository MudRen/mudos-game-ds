// copyright from /cmds/arch/kickout.c
// copy by JS@DS

#include <ansi.h>
inherit ROOM; 
void create() 
{ 
        seteuid(getuid()); 
        set("channel_id", "���u���F(Kickout)");
        set("short", HIW"���p�շǳƪ��ж�"NOR); 
        set("long", @LONG
�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L
�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L
�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L
�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L�L
LONG
);   
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"workroom",
]));
        set("light",1);
        setup();
}
int init()
{ 
    add_action("do_kickout","kt");
}
int do_kickout(string arg)
{ 
        object ob; 
  if (!arg) return notify_fail("���O�榡: kt <id> \n");
    if(arg=="jangshow") return notify_fail("�Q�� Jangshow�H�A���U�u�a�I�I\n");
    "/cmds/arch/kickout"->main(this_player(),ob->query("ob"));
  if( ob = find_player(arg) )
  return 1;
  "/cmds/arch/kickout"->main(this_player(), ob->query("id"));
  return 1;
}


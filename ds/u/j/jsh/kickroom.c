// copyright from /cmds/arch/kickout.c
// copy by JS@DS

#include <ansi.h>
inherit ROOM; 
void create() 
{ 
        seteuid(getuid()); 
        set("channel_id", "離線精靈(Kickout)");
        set("short", HIW"為小白準備的房間"NOR); 
        set("long", @LONG
無無無無無無無無無無無無無無無無無無無無無無無無無無無無
無無無無無無無無無無無無無無無無無無無無無無無無無無無無無無
無無無無無無無無無無無無無無無無無無無無無無無無無無無無無無
無無無無無無無無無無無無無無無無無無無無無無無無無無無無無無
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
  if (!arg) return notify_fail("指令格式: kt <id> \n");
    if(arg=="jangshow") return notify_fail("想踢 Jangshow？你先下線吧！！\n");
    "/cmds/arch/kickout"->main(this_player(),ob->query("ob"));
  if( ob = find_player(arg) )
  return 1;
  "/cmds/arch/kickout"->main(this_player(), ob->query("id"));
  return 1;
}


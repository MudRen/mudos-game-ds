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
        object ob,me,users;
        string msgs;
        me = this_player(); 
       if (!arg || sscanf(arg,"%s because %s",arg,msgs)!=2)
 return notify_fail("指令格式: kt <id> because <理由> \n");
 message("world:world1:vision","\n【七域快報】 天殺的"HIY+ob->name(1)+HIR"竟敢因為『"HIY+msgs+HIR"』這個鳥理由頂撞了 "HIW+me->name(1)+HIR"，被狠狠踢出遊戲了！！ ，\n\n"NOR,users());
  if( ob = find_player(arg) )
  "/cmds/arch/kickout"->main(this_player(), ob->query("id")); 
  return 1;
}


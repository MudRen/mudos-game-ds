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
        object ob,me,users;
        string msgs;
        me = this_player(); 
       if (!arg || sscanf(arg,"%s because %s",arg,msgs)!=2)
 return notify_fail("���O�榡: kt <id> because <�z��> \n");
 message("world:world1:vision","\n�i�C��ֳ��j �ѱ���"HIY+ob->name(1)+HIR"�����]���y"HIY+msgs+HIR"�z�o�ӳ��z�ѳ����F "HIW+me->name(1)+HIR"�A�Q������X�C���F�I�I �A\n\n"NOR,users());
  if( ob = find_player(arg) )
  "/cmds/arch/kickout"->main(this_player(), ob->query("id")); 
  return 1;
}

